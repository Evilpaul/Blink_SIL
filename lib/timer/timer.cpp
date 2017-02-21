#include <Arduino.h>
#include "timer.h"

static volatile bool timer_trigger;

void timer_init()
{
	// initialise variables
	timer_trigger = false;

	noInterrupts(); // stop interrupts

	// set timer1 interrupt at 200Hz
	TCCR1A = 0; // set entire TCCR1A register to 0
	TCCR1B = 0; // same for TCCR1B
	TCNT1  = 0; // initialize counter value to 0

	// set compare match register for 200Hz increments
	OCR1A = (F_CPU / (200 * 64)) - 1; // must be < 65536

	// turn on CTC mode
	TCCR1B |= (1 << WGM12);

	// Set CS12 and CS10 bits for 64 prescaler
	TCCR1B |= (1 << CS11) | (1 << CS10);

	// enable timer compare interrupt
	TIMSK1 |= (1 << OCIE1A);

	interrupts(); // allow interrupts
}

bool timer_getTrigger()
{
	bool retVal;

	noInterrupts(); // stop interrupts
	retVal = timer_trigger; // set the return status to the current flag status
	timer_trigger = false; // clear flag
	interrupts(); // allow interrupts

	return retVal;
}

ISR(TIMER1_COMPA_vect)
{
	// timer1 interrupt 1Hz toggles pin 13 (LED)
	// generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)
	timer_trigger = true;
}
