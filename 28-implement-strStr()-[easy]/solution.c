// started 11/17/16 10:40 pm - 12:00 AM
// Note to self -> try again from scratch! took too long to implement!! submitted 4 mistake submission!! 
//				-> improve code readability!!
#include <stdio.h>

int strStr(char* haystack, char* needle) {
    
	int result = -1;
    
    if(*needle == NULL){
        return 0;
    }

	int count = 0;
	int possibleMatch = 0;
	char firstChar = *needle;
	char *savedHay;
    char *savedNeedle = needle;
    int savedCount;
    
	while(*haystack != NULL){

		if(possibleMatch == 1){
		
			if(*needle != NULL){
			   //printf("n:%c - h:%c \n",*needle,*haystack);
				if(*needle != *haystack){
					possibleMatch = 0;
					result = -1;
					
					count = savedCount;
					haystack = savedHay;
				    needle = savedNeedle;
				}else{
				    needle++;
				}
			}else{
				break;
			}
		}else{
			if(*haystack == firstChar){
				result = count;
				//printf("result: %d \n", result);
				savedHay = haystack;
				savedCount = count;
				possibleMatch = 1;
				needle++;
			}
		}
		haystack++;
		count++;
	}
	if(result != -1 && *haystack == NULL && *needle != NULL){    //case in which needle is longer than haystack. e.g. hay: aaa, need: aaaa
	    result = -1;
	}
	return result;

}

/*
"mississippi"
"issipi"
"mississippi"
"issip"
"a"
"a"
"abb"
"ab"
"ab"
"abb"
"a"
"aaa"
"aaa"
"aaaa"
""
"abc"
""
""
"abcdef"
""
"a"
""
"ab"
"a"
"ab"
"b"
"abcdog"
"dog"
"abcd-og"
"dog"
"ahh"
"h"
*/