//12/22/16 (coding) 8:10PM - 9:01PM

#include <string.h>


// more optimized solution -> less memmory access
bool isIsomorphic(char* s, char* t) {
    
    bool result = true;

    char asciiArr1[128];
    char asciiArr2[128];

    memset(asciiArr1,NULL,128);
    memset(asciiArr2,NULL,128);

    while(*s != NULL && *t != NULL){
    	
    	if(asciiArr1[*s] == NULL) {
    	    asciiArr1[*s] = *t;
    	}
    	if(	asciiArr2[*t] == NULL){
    	    asciiArr2[*t] = *s;
    	}
    
    	if(asciiArr1[*s] != *t || asciiArr2[*t] != *s){
    		result = false;
    		break;
    	}
    	s++;
    	t++;
    }
    if(*s != NULL || *t != NULL){
    	result = false;
    }
    return result;
}

/*
bool isIsomorphic(char* s, char* t) {
    
    bool result = true;

    char asciiArr1[128];
    char asciiArr2[128];

    memset(asciiArr1,NULL,128);
    memset(asciiArr2,NULL,128);

    while(*s != NULL && *t != NULL){
    	 
    	asciiArr1[*s] = asciiArr1[*s] == NULL ? *t : asciiArr1[*s];
    	asciiArr2[*t] = asciiArr2[*t] == NULL ? *s : asciiArr2[*t];
    	
    	if(asciiArr1[*s] != *t || asciiArr2[*t] != *s){
    		result = false;
    		break;
    	}
    	s++;
    	t++;
    }
    if(*s != NULL || *t != NULL){
    	result = false;
    }
    return result;
}

