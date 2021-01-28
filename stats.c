/* Module includes */
#include "stats.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

/* Function name: compute_statistics
   Function Brief- Computes Min, Max and Average of given numbers
   Paramaters - float*, int
   Return Type - stats_s
*/
stats_s compute_statistics(float* numberset, int setlength)
{
    int itr, j;
    float key = 0, sum = 0;
    stats_s statisticalData;
    
    /* Average of numbers */
    for(itr=0;itr<setlength;itr++)
    {
        sum += numberset[itr];
    }
    statisticalData.average = sum/setlength;
    
    /* Sorting range of numbers */
    for (itr = 1; itr < setlength; itr++) 
    { 
        key = numberset[itr]; 
        j = itr - 1; 
        while (j >= 0 && numberset[j] > key) { 
            numberset[j + 1] = numberset[j]; 
            j = j - 1; 
        } 
        numberset[j + 1] = key; 
    }
    
    statisticalData.min = numberset[0];
    statisticalData.max = numberset[setlength-1]; 

    return statisticalData;
}

/* Function name: check_and_alert
   Function Brief- Alerts if max is > threshold
   Paramaters - float, alerter_funcptr, stats_s
   Return Type - void
*/

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], stats_s computedStats)
{ 
    /* Call alerters if max is > threshold */
    if(computedStats.max > maxThreshold)
    {
        if(alerters[0] != NULL)
        {
            (*alerters[0])();
        }
        if(alerters[1] != NULL)
        {
            (*alerters[1])();
        }
    }
    else
    {
	/* do nothing*/
    }
}


