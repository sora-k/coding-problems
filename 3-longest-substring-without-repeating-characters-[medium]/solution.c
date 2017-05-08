#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

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

int main(){

	int len = 5;
	char *test[len];
	test[0] =  "abcabcbb";
	test[1] = "bbbbb";
	test[2] = "pwwkew";
	test[3] = "c";
	test[4] = "aab";
	int i;
	for(i = 0; i < len; i++){ 
	   int L = lengthOfLongestSubstring(test[i]);
	   printf("result : %d \n", L);
	}
	return 0;
}

