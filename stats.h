#include <stdlib.h>
#include "alerters.h"

/* Structure for Statistics */
typedef struct Statistics{
  float min;
  float max;
  float average; 
}stats_s;

/* MACROs and Variables */
#define TRUE 1
#define FALSE 0

/* Public decalarations */
stats_s compute_statistics(float* numberset, int setlength);
typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], stats_s computedStats);

/* Extern variables */
extern int emailAlertCallCount;
extern int ledAlertCallCount;

