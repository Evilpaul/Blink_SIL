#include <Arduino.h>
#include "sched_rate.h"
#include "timer.h"

static bool led_state;

void setup()
{
	// initialise variables
	led_state = HIGH;

	// set pins as outputs
	pinMode(LED_BUILTIN, OUTPUT);

	// initialise the timer module
	timer_init(SCHEDULER_PERIOD);
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
