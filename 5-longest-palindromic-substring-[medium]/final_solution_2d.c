#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAX_INPUT 1000
#define ASCII_SIZE 300
//To Run, paste this in Leetcode
int is_palin(char str[], int startInd, int endInd){
	
	int result = 1;

	while(startInd < endInd){
		if(str[startInd] != str[endInd]){
			result = 0;
			break;
		}
		startInd++;
		endInd--;
	}
	return result;
}
char * longestPalindrome(char *s){

	int resultMaxLen = 1;
	char * result = s;
	char * head = s;
	int strLen = 0;

	int maxCharCnt;
	int charCnt[ASCII_SIZE];
	int *tmpCharCnt = (int *) malloc(sizeof(int) * ASCII_SIZE);
	int mapToRepeatedCharIndsArr[ASCII_SIZE];
	int repeatedCharCnt = 0;
	memset(charCnt,0,sizeof(charCnt));
	memset(tmpCharCnt,0,sizeof(int) * ASCII_SIZE);
	memset(mapToRepeatedCharIndsArr,-1,sizeof(mapToRepeatedCharIndsArr));

	/*
		Set up work
	*/
	int i = 0;
	char *tmpSeen = (char *) malloc(sizeof(char) * ASCII_SIZE);
	memset(tmpSeen,'0',sizeof(char) * ASCII_SIZE);
	while(*s){	
		charCnt[*s]++;			// Count number of each char  and size of string
		tmpCharCnt[*s]++;
		strLen++;

		if(charCnt[*s] > 1){	// Count number of repeated char and map to repeatedCharInds
			if(tmpSeen[*s] == '0'){
				repeatedCharCnt++;
				tmpSeen[*s] = '1';
			}	
			
			if((mapToRepeatedCharIndsArr[*s] == -1)){
				mapToRepeatedCharIndsArr[*s] =  i;
				i++;
			}
		}
		s++;
	}
	free(tmpSeen);

	s = head;
	i = 0;

	int *repeatedCharInds[repeatedCharCnt];
	int sizeOfIndsArr[repeatedCharCnt];
	memset(repeatedCharInds,0,sizeof(repeatedCharInds));
	while(*s){	// Get inds for each repeated chars, init array to store indices, store the inds of each repeated chars in descending order
		if(charCnt[*s] > 1){
			if(tmpCharCnt[*s] >= 1){
				int ind = mapToRepeatedCharIndsArr[*s];
				int indSub = tmpCharCnt[*s] - 1;

				if(repeatedCharInds[ind] == 0){
					int size = charCnt[*s];
					sizeOfIndsArr[ind] = size;
					repeatedCharInds[ind] = (int *) malloc(sizeof(int) * size);
				}
				repeatedCharInds[ind][indSub] = i;
				tmpCharCnt[*s]--;
			}
		}
		i++;
		s++;
	}
	free(tmpCharCnt);

	/*
		Actual solution
	
	*/
	
	int k; int l; int found = -1; int resultStartInd; int resultEndInd;
	for(i = 0; i < repeatedCharCnt; i++){
		int *arr = repeatedCharInds[i];
		int arrSize = sizeOfIndsArr[i];
		
		for(k = arrSize - 1; k >= 0 ; k--){		//Note: the inds are in descending order
			int startInd = arr[k];
			
			for(l = 0; l < arrSize; l++){
				int endInd = arr[l];
				int currLen = (endInd - startInd) + 1;
				
				if(currLen > resultMaxLen){
					int valid = is_palin(head,startInd,endInd);
					
					if(valid == 1){
						found = 1;
						resultStartInd = startInd;
						resultEndInd = endInd;
						resultMaxLen = currLen;
					}
				}else{
					break;
				}
		
			}
		}
	}
	if(found == 1){
		result = head + resultStartInd;
		if(head[resultEndInd + 1] != '\0'){
			head[resultEndInd + 1] = '\0';
		}
	}
	if(found == -1){
		if(strLen > 1){
			if(head[1] != '\0'){
				head[1] = '\0';
			}
		}
	}
	/*
		Clean up
	*/
	for(i = 0; i < repeatedCharCnt ; i++){
		free(repeatedCharInds[i]);
	} 

	s = head;

	return result;
}
