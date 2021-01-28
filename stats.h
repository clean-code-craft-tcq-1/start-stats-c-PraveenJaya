typedef struct Stats{
	  float min;
	  float max;
	  float average; 
	}stats_t;
	
	stats_t compute_statistics(float* numset, int setlen);
	
	typedef void (*alerter_funcptr)();
	void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);
	
	extern int emailAlertCallCount;
	extern int ledAlertCallCount;

