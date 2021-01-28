#include "stats.h"
	
	stats_t compute_statistics(float* numset, int setlen)
	{
	    int i, j;
	    float key = 0, sum = 0;
	    stats_t statData;
	    
	    /* Sorting the given number */
	    for (i = 1; i < setlength; i++) 
	    { 
	        key = numset[i]; 
	        j = i - 1; 
	        while (j >= 0 && numset[j] > key) { 
	            numset[j + 1] = numset[j]; 
	            j = j - 1; 
	        } 
	        numset[j + 1] = key; 
	    }
        
        /* Average of numbers */
	    for(i=0;i<setlength;i++)
	    {
	        sum += numset[i];
	    }
	    statData.average = sum/setlength;
	    statData.min = numset[0];
	    statData.max = numset[setlength-1]; 
	
	    return statData;
	}

