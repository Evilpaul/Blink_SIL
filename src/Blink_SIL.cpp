#include <Arduino.h>
#include "timer.h"

#define TIMER_PERIOD_MS 5

static bool led_state;

void setup()
{
	// initialise variables
	led_state = HIGH;

	// set pins as outputs
	pinMode(LED_BUILTIN, OUTPUT);

	// initialise the timer module
	timer_init(TIMER_PERIOD_MS);
} // end setup

void loop()
{
	bool trigger;

	// do other things here
	trigger = timer_getTrigger();
	if(trigger)
	{
		timer_clearTrigger();

		led_state ^= 1;
		digitalWrite(LED_BUILTIN, led_state);
	}
}
