#include <Arduino.h>
#include "timer.h"

static volatile bool timer_trigger;

static void calulate_prescaler()
{
	uint32_t prescaler = (F_CPU / 1000) * TIMER_PERIOD_MS;
	prescaler = prescaler & (-prescaler);

	switch(prescaler)
	{
		case 0:
		case 1:
		case 2:
		case 4:
			prescaler = 1;
			TCCR1B |= (1 << CS10);
			break;
		case 8:
		case 16:
		case 32:
			prescaler = 8;
			TCCR1B |= (1 << CS11);
			break;
		case 64:
		case 128:
			prescaler = 64;
			TCCR1B |= (1 << CS11) | (1 << CS10);
			break;
		case 256:
			prescaler = 256;
			TCCR1B |= (1 << CS12);
			break;
		default:
			prescaler = 1024;
			TCCR1B |= (1 << CS12) | (1 << CS10);
			break;
	}

	prescaler = ((F_CPU / (1000 * prescaler)) * TIMER_PERIOD_MS) - 1;

	// set compare match register for nHz increments
	OCR1A = (uint16_t)min(prescaler, 65535);
}

void timer_init()
{
	// initialise variables
	timer_trigger = false;

	noInterrupts(); // stop interrupts

	// set timer1 interrupt at 200Hz
	TCCR1A = 0; // set entire TCCR1A register to 0
	TCCR1B = 0; // same for TCCR1B
	TCNT1  = 0; // initialize counter value to 0

	calulate_prescaler();

	// turn on CTC mode
	TCCR1B |= (1 << WGM12);

	// enable timer compare interrupt
	TIMSK1 |= (1 << OCIE1A);

	interrupts(); // allow interrupts
}

bool timer_getTrigger()
{
	return timer_trigger;
}

void timer_clearTrigger()
{
	timer_trigger = false; // clear flag
}

ISR(TIMER1_COMPA_vect)
{
	// timer1 interrupt 1Hz toggles pin 13 (LED)
	// generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)
	timer_trigger = true;
}
