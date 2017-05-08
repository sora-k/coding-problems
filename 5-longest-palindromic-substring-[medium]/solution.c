#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAX_INPUT 1000
#define ASCII_SIZE 300

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
	// printf("repeatedCharCnt %d\n", repeatedCharCnt );
	// for(i = 0; i < repeatedCharCnt; i++){
	// 	int j;
	// 	for(j = 0; j < sizeOfIndsArr[i] ; j++){
	// 		printf("%d ",(int)repeatedCharInds[i][j]);
	// 	}
	// 	printf("\n");
	// }

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
				if(endInd == 497){
					int p = 0;
				}
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
	printf("%s\n",result);
	/*
		Clean up
	*/
	for(i = 0; i < repeatedCharCnt ; i++){
		free(repeatedCharInds[i]);
	} 

	s = head;

	return result;
}

void main(){
	//"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	//"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	char test0[] = "12348951015108711"; char test0s[] = "01510";	//note- the other solution is "51015"
	char test1[] = "01510";				char test1s[] = "01510";
	char test2[] = "0110";				char test2s[] = "0110";
	char test3[] = "aaa";				char test3s[] = "aaa";
	char test4[] = "aa";				char test4s[] = "aa";
	char test5[] = "ab";				char test5s[] = "a";
	char test6[] = "a";					char test6s[] = "a";
	char test7[] = "";					char test7s[] = "";
	char test8[] = "adam";				char test8s[] = "ada";
	char test9[] = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
	char test9s[] = "ranynar";
	char test10[] =  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char test10s[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char *result;
	
	struct timeval  tv1, tv2;
	gettimeofday(&tv1, NULL);

	printf("test0 result: %d - 0 means good\n", (strcmp(longestPalindrome(test0),test0s)));
	printf("test1 result: %d - 0 means good\n", (strcmp(longestPalindrome(test1),test1s)));
	printf("test2 result: %d - 0 means good\n", (strcmp(longestPalindrome(test2),test2s)));
	printf("test3 result: %d - 0 means good\n", (strcmp(longestPalindrome(test3),test3s)));
	printf("test4 result: %d - 0 means good\n", (strcmp(longestPalindrome(test4),test4s)));
	printf("test5 result: %d - 0 means good\n", (strcmp(longestPalindrome(test5),test5s)));
	printf("test6 result: %d - 0 means good\n", (strcmp(longestPalindrome(test6),test6s)));
	printf("test7 result: %d - 0 means good\n", (strcmp(longestPalindrome(test7),test7s)));
	printf("test8 result: %d - 0 means good\n", (strcmp(longestPalindrome(test8),test8s)));
	printf("test9 result: %d - 0 means good\n", (strcmp(longestPalindrome(test9),test9s)));
	printf("test10 result: %d - 0 means good\n", (strcmp(longestPalindrome(test10),test10s)));

	gettimeofday(&tv2, NULL);
	printf ("Total time = %f seconds\n",
         (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec));

}