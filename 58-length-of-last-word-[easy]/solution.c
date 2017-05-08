//11/20/16 12:00 am - 12:11 am
#include <stdio.h>
#include <ctype.h>

int lengthOfLastWord(char* s) {
    
    int result = 0;
    int foundWord = 0;
    while(*s != NULL){
    	if(foundWord == 1){
    		if(isspace(*s) == 0){
    			result++;
    		}else{
    			foundWord = 0;
    		}
    	}else{
    		if(isspace(*s) == 0){
    			foundWord = 1;
    			result = 1;
    		}
    	}
    	s++;
    }
    return result;

}
/*
""
"a"
"hello "
"hello        "
"      hello"
"hello a"

*/