#include "stats.h"
	
	stats_t compute_statistics(float* numset, int setlen)
	{
	    int itr, j;
	    float key = 0, sum = 0;
	    stats_t statData;
	    
	    /* Sorting the given number */
	    for (itr = 1; itr < setlen; itr++) 
	    { 
	        key = numset[itr]; 
	        j = itr - 1; 
	        while (j >= 0 && numset[j] > key) { 
	            numset[j + 1] = numset[j]; 
	            j = j - 1; 
	        } 
	        numset[j + 1] = key; 
	    }
        
            /* Calculate Average of numbers */
	    for(itr=0;itr<setlen;itr++)
	    {
	        sum += numset[i];
	    }
	    statData.average = sum/setlen;
	    statData.min = numset[0];
	    statData.max = numset[setlen-1]; 
	
	    return statData;
	}

