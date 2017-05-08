#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//To Run, paste this in Leetcode
int lengthOfLongestSubstring(char* s) {
        
	char ascii[255];
	memset(ascii,'\0',sizeof(ascii));
	
	int maxL = 0;
	int len = 0;
	char *p = s;

	while(*s != '\0'){
	   
	   if(ascii[*p] == '\0' && *p != '\0'){
		ascii[*p] = '1';
	   	len++;
		p++;
	   }
	   else{
		maxL = (len > maxL) ? len : maxL;
		memset(ascii,'\0',sizeof(ascii));
		len = 0;
		s++;
		p = s;
	   }
        }
	maxL = (len > maxL) ? len : maxL;
    	return maxL;
}
