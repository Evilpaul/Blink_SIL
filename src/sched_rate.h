#include <Arduino.h>

#define TIMER_PERIOD_5MS 5
#define TIMER_PERIOD_10MS 10
#define TIMER_PERIOD_20MS 20
#define TIMER_PERIOD_50MS 50
#define TIMER_PERIOD_100MS 100
#define TIMER_PERIOD_200MS 200
#define TIMER_PERIOD_500MS 500
#define TIMER_PERIOD_1S 1000
#define TIMER_PERIOD_2S 2000
#define TIMER_PERIOD_5S 5000
#define TIMER_PERIOD_10S 10000

#define SCHEDULER_PERIOD TIMER_PERIOD_5MS

#if SCHEDULER_PERIOD <= TIMER_PERIOD_5MS
const uint16_t TIME_COUNT_5MS = TIMER_PERIOD_5MS / SCHEDULER_PERIOD;
#endif
#if SCHEDULER_PERIOD <= TIMER_PERIOD_10MS
const uint16_t TIME_COUNT_10MS = TIMER_PERIOD_10MS / SCHEDULER_PERIOD;
#endif
#if SCHEDULER_PERIOD <= TIMER_PERIOD_20MS
const uint16_t TIME_COUNT_20MS = TIMER_PERIOD_20MS / SCHEDULER_PERIOD;
#endif
#if SCHEDULER_PERIOD <= TIMER_PERIOD_50MS
const uint16_t TIME_COUNT_50MS = TIMER_PERIOD_50MS / SCHEDULER_PERIOD;
#endif
#if SCHEDULER_PERIOD <= TIMER_PERIOD_100MS
const uint16_t TIME_COUNT_100MS = TIMER_PERIOD_100MS / SCHEDULER_PERIOD;
#endif
#if SCHEDULER_PERIOD <= TIMER_PERIOD_200MS
const uint16_t TIME_COUNT_200MS = TIMER_PERIOD_200MS / SCHEDULER_PERIOD;
#endif
#if SCHEDULER_PERIOD <= TIMER_PERIOD_500MS
const uint16_t TIME_COUNT_500MS = TIMER_PERIOD_500MS / SCHEDULER_PERIOD;
#endif
#if SCHEDULER_PERIOD <= TIMER_PERIOD_1S
const uint16_t TIME_COUNT_1S = TIMER_PERIOD_1S / SCHEDULER_PERIOD;
#endif
#if SCHEDULER_PERIOD <= TIMER_PERIOD_2S
const uint16_t TIME_COUNT_2S = TIMER_PERIOD_2S / SCHEDULER_PERIOD;
#endif
#if SCHEDULER_PERIOD <= TIMER_PERIOD_5S
const uint16_t TIME_COUNT_5S = TIMER_PERIOD_5S / SCHEDULER_PERIOD;
#endif
#if SCHEDULER_PERIOD <= TIMER_PERIOD_10S
const uint16_t TIME_COUNT_10S = TIMER_PERIOD_10S / SCHEDULER_PERIOD;
#endif
