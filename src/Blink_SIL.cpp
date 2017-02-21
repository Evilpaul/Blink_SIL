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
#include "timer.h"

static bool led_state;

void setup()
{
	// initialise variables
	led_state = HIGH;

	// set pins as outputs
	pinMode(LED_BUILTIN, OUTPUT);

	// initialise the timer module
	timer_init();
} // end setup

void loop()
{
	bool trigger;

	// do other things here
	trigger = timer_getTrigger();
	if(trigger)
	{
		led_state ^= 1;
		digitalWrite(LED_BUILTIN, led_state);
	}
}
