#ifndef _TIMER_H_
#define _TIMER_H_

#define TIMER_PERIOD_MS 5

void timer_init();
bool timer_getTrigger();
void timer_clearTrigger();

#endif /* _TIMER_H_ */
