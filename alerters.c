/* Module includes */
#include "stats.h"

/* Function name: emailAlerter
   Function Brief- This API will be called to notify threshold > max
   Paramaters - void
   Return Type - void
*/
void emailAlerter(void)
{
    emailAlertCallCount = 1;
}

/* Function name: ledAlerter
   Function Brief- This API will be called to notify threshold > max
   Paramaters - void
   Return Type - void
*/
void ledAlerter()
{
     ledAlertCallCount = 1;
}
