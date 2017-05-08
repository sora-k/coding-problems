//started 9/11/16 - 9/12/16 Took 1 day- including sleep for 10 hours and play time on and off for 6 hours

#include <stdio.h>
#include <limits.h>
#include <ctype.h>

#define MINUS '-'
#define PLUS '+'
#define ZERO_CHAR '0'
#define MAX_DIG 10

int myAtoi(char* str) {
    
    int result = 0;

    char *s = str;
    int valid = 0;
    while(*s != NULL){ // find first valid digit position

    	if((*s == MINUS) || (*s == PLUS) || (isdigit(*s) != 0)){ 
    		valid = 1;
    		break;
    	}else{
    		if(isspace(*s) == 0){
    			break;
    		}
    	}
    	s++;
    }

    int digCnt = 0;
    int overFlow = 0;
    int greaterThanLimit = 0;
    int refMaxMin = INT_MAX;
    int refDivisor = 1000000000;
    int negative = 0;
    int chkOverflow = 0;
    if(valid == 1){ // do number conversion
    	if(*s == MINUS || *s == PLUS){
    		negative = (*s == MINUS) ? 1 : 0;
    		refMaxMin  = (negative == 1) ? INT_MIN : refMaxMin;
    		s++;
    	}

    	while(*s){
    		if(isdigit(*s) != 0){
    			digCnt++;
    			if(digCnt > MAX_DIG){ 
    				overFlow = 1;
    				break;
    			}
    			else{
    				int digit = (*s - ZERO_CHAR);
    				
    				if(chkOverflow == 0){	//check each digit against INT_MAX or INT_MIN
    					int refDig = refMaxMin / refDivisor;
	    				refDig %= 10;
	    				refDig = refDig < 0 ? refDig * -1 : refDig;
	    				refDivisor /= 10;

		    			if(digit > refDig){	
		    				greaterThanLimit = 1;
		    				chkOverflow = 1;
		    			}else{                     
		    				if(digit < refDig){
		    					chkOverflow = 1;
		    				}
		    			}
	    			}

	    			result *= 10;
	    			result += digit; 
	    			s++;
	    		}
    		}else{
    			break;
    		}
    	}
    }
    if(negative == 1){
    	result *= -1;
    }
    if(overFlow == 1 || (greaterThanLimit == 1 && digCnt == MAX_DIG)) {
    	result = (negative == 1) ? INT_MIN : INT_MAX;
    }
    return result;
}