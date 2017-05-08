// started 9:12 p.m. 11/13/16 - 9:35 p.m. 11/14/16 (including 10 sleep + 8 work + 5 hrs of play)

#include <stdio.h>
#include <stdlib.h>

// NOTE: input strings are defined as static string NOT array of characters, they're immutable

int count_char(char *s){
    
	int count = 0;
	while(*s != '\0'){
		count++;
		s++;
	}
	return count;

}
char* longestCommonPrefix(char** strs, int strsSize) {
   
   char *result;

   if(strsSize > 0){
       int cnt = count_char(*strs);
       result = (char *) malloc(sizeof(char) * (cnt + 1));
       result[cnt] = '\0';
       
       
       int done,i,k = 0;
       for(i = 0; i < cnt; i++){
    
       		char c = strs[0][i];
       		for(k = 1; k < strsSize; k++){
       			if(c != strs[k][i]){
       				done = 1;
       				break;
       			}
       		}
       		result[i] = (done == 1) ? '\0': c;
       		if(done == 1){break;}
       }
   }else{
       result = (char *) malloc(sizeof(char) * (1));
       result[0] = '\0';
   }
   
   return result;
}

/*
[]
[""]
["dabxxx"]
["xxxxx","xxxx","xxx"]
["abcbb","abcxx,"abc"]
["","",""]
["","zabcxxx","dabxxx"]
["kabc","zabcxxx","dabxxx"]
*/