#ifndef _TIMER_H_
#define _TIMER_H_

#include <Arduino.h>

void timer_init(uint16_t timeMS);
bool timer_getTrigger();
void timer_clearTrigger();

#endif /* _TIMER_H_ */
