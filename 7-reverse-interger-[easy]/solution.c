//started 9/11/16 - 9/12/16 Took 1 day- including sleep for 10 hours and play time on and off for 6 hours
#include <stdio.h>
#include <limits.h>

#define INT_MAX_DIGIT 10
int reverse(int x){

	int result = 0;
	
	int negative = (x < 0) ? 1 : 0;
	int chkIfGreaterThanRef = 1;

	int refDivisor = 1000000000;
	int refMaxMin = (negative == 1) ? INT_MIN : INT_MAX;
	int ind = 0;
	int digCnt = 0;
	int greaterThanRef = 0;
	while(x != 0){
        digCnt++;
        
		int r = x % 10;
		r = (negative == 1) ? r * -1 : r;
	   
		if(chkIfGreaterThanRef == 1){
			int refDig = refMaxMin / refDivisor;
			refDig %= 10;
			refDig = (refDig < 0) ? refDig * -1 : refDig;
			refDivisor /= 10;

			if(r > refDig){
				greaterThanRef = 1;
				chkIfGreaterThanRef = 0;
			}
			else{
				if(r < refDig){
					chkIfGreaterThanRef = 0;
				}
			}
		}
		
		result *= 10;
		result += r;
		x /= 10;
		ind++;
	}
	if(negative == 1){
		result *= -1;
	}
	if(greaterThanRef == 1 && digCnt == INT_MAX_DIGIT){
	    result = 0;
	}
	return result;
	
}