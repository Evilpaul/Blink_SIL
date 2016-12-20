// timer interrupts
// by Amanda Ghassaei
// June 2012
// http://www.instructables.com/id/Arduino-Timer-Interrupts/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 */
// timer setup for timer1.
// For arduino uno or any board with ATMEL 328/168.. diecimila, duemilanove, lilypad, nano, mini...
// this code will enable one arduino timer interrupt.
// timer1 will interrupt at 1Hz
#include <Arduino.h>

static volatile boolean timer_trigger;
static boolean led_state;

void init_timer()
{
	noInterrupts(); // stop interrupts

	// set timer1 interrupt at 1Hz
	TCCR1A = 0; // set entire TCCR1A register to 0
	TCCR1B = 0; // same for TCCR1B
	TCNT1  = 0; // initialize counter value to 0

	// set compare match register for 1hz increments
	//OCR1A = 15624; // = (16*10^6) / (1*1024) - 1 (must be <65536)
	OCR1A = 1952; // = (16*10^6) / (1*1024) - 1 (must be <65536)

	// turn on CTC mode
	TCCR1B |= (1 << WGM12);

	// Set CS12 and CS10 bits for 1024 prescaler
	TCCR1B |= (1 << CS12) | (1 << CS10);

	// enable timer compare interrupt
	TIMSK1 |= (1 << OCIE1A);

	interrupts(); // allow interrupts
}

void setup()
{
	// initialise variables
	timer_trigger = false;
	led_state = HIGH;

	// set pins as outputs
	pinMode(LED_BUILTIN, OUTPUT);

	// initialise the timer module
	init_timer();
} // end setup

ISR(TIMER1_COMPA_vect)
{
	// timer1 interrupt 1Hz toggles pin 13 (LED)
	// generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)
	timer_trigger = true;
}

void loop()
{
	// do other things here
	if(timer_trigger)
	{
		timer_trigger = false;

		led_state ^= 1;
		digitalWrite(LED_BUILTIN, led_state);
	}
}
