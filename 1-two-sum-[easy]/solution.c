/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
void merge(int nums[], int start, int end, int size){
	
	int *arrCpy = (int*) malloc(sizeof(int)*size);
	memcpy(arrCpy,nums, size*sizeof(int)); 
		
	int endL = (start + end)/2;
	int leftInd = start;
	int rightInd = endL + 1;
	int i = start;

	while( leftInd <= endL){
	    int left = arrCpy[leftInd];
	    int right = arrCpy[rightInd];
		
  	    if(left <= right || rightInd > end){
		nums[i] = left;
		leftInd++; 
	    }
	    else{
		nums[i] = right;
		rightInd++;
	    }
	    i++;
	} 	
	
	while( rightInd <= end){
	   nums[i] = arrCpy[rightInd];
	   i++;
	   rightInd++;  
	}
	free(arrCpy);
	return;
}
void merge_sort(int nums[],int start, int end, int size){
	
	if(start >= end){
	   return;
	}
	int middle = (end + start)/2;
	merge_sort(nums, start, middle,size);
	merge_sort(nums, middle + 1, end,size);
	merge(nums, start, end, size);
	
}

void merge_sort_test(){

	int oneElementArr[1] = {0};
	int twoElementArr[2] = {1,0};
	int someArrO[5] = {5,4,3,2,1};
	int someArrE[6] = {6,5,4,3,2,1};

	int expectedSomeArrO[5] = {1,2,3,4,5};
	int expectedSomeArrE[6] = {1,2,3,4,5,6};
	int expectedTwoElementArr[2] = {0,1};
	int expectedOneElementArr[1] = {0};

	merge_sort(someArrO,0,4,5);
	merge_sort(someArrE,0,5,6);
	merge_sort(twoElementArr,0,1,2);
	merge_sort(oneElementArr,0,0,1);
	
	//Note: array[10] , sizeof(array) = 40 (in bytes)
	//	sizeof(int) = 4 (in bytes)
	
	int result = 0;
	result += memcmp(someArrO,expectedSomeArrO,sizeof(someArrO)); 
	result += memcmp(someArrE,expectedSomeArrE,sizeof(someArrE));
	result += memcmp(twoElementArr,expectedTwoElementArr,sizeof(twoElementArr));
	result += memcmp(oneElementArr,expectedOneElementArr,sizeof(oneElementArr)); 
	
	printf("mergesort test result = %d [note: zero indicates success]\n", result);
	
	return;
}

int bin_search(int arr[],int start,int end,int countInd,int num){
	
	int startSub = start;
	int endSub = end;
	int middle = (start + end)/2;
	int count = 1; //keep count of repeated element.
	int current;

	while(startSub <= endSub){

	   current = arr[middle];
	     	
	   if(current == num && count == countInd){
		return middle;
	   }
	   if(current == num){
	   	count++;
	   }
	   if(num < arr[middle]){
		endSub = middle - 1;   
		middle = (middle + startSub)/2;
	   }
	   else{
		startSub = middle + 1;
		middle = (middle + endSub + 1)/2;
	   }

	}
	return -1;
}

void bin_search_test(){

	int arrE[] = {1,2,3,4,5,6,7,8,9,10};
	int arrO[] = {1,2,3,4,5,6,7,8,9,10,11};
	int arrR[] = {1,2,2,3,3,5,5,6,7,8};
	int arrRand[] = {1,2,5,8,9,10,15};
	int arrS[] = {2};
	int arrT[] = {1,2};
	int arrTr[] = {1,2,3};
	
	int result = bin_search(arrE,0,9,1,2);
	    result += bin_search(arrS,0,0,1,0);
	    result += bin_search(arrS,0,0,1,2);
	    result += bin_search(arrT,0,1,1,1);
	    result += bin_search(arrT,0,1,1,2);
	    result += bin_search(arrR,0,9,1,3);
	int x = 0;
}

int index_of(int nums[],int target,int countIn,int size){

	int i;
	int count = 1; //keep count of repeated element.
	int current;

	for(i = 0; i < size; i++){
	   current = nums[i];	  
	   if(current == target && count == countIn){
		return i;
	   }
	   if(current == target){
		count++;
	   }
	}
	return -1;

}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
  	
	int i;
	int *arrOut = (int*) malloc(sizeof(int)*2);	
	int first,second, result;
	int *original = (int*) malloc(sizeof(int)*numsSize);
	int countInd = 1; //indicate index_of() and bin_search() to return the first found element.

	memcpy(original,nums, numsSize*sizeof(int)); 
	merge_sort(nums,0,numsSize - 1,numsSize);
	
	for(i = 0 ; i < numsSize; i++){
	   first = nums[i];
	   second = target - first;
	   
	   result = bin_search(nums,0,numsSize - 1, countInd,second);   
	   if(second == first){ // find the second repeat element
		result += bin_search(nums,0,numsSize - 1, countInd + 1, second);
	   }	  
	   if(result > -1 ){
		arrOut[0] = index_of(original,second,countInd,numsSize);
		countInd = (first == second) ? 2 : 1;
		arrOut[1] = index_of(original,first,countInd,numsSize);
	   }
	   countInd = 1;
	}
	free(original);
	return arrOut;
}

void main(){

	int x = 200;
	printf("Hello World \n");
	//merge_sort_test();
	//bin_search_test();

	int arrIn[] = {2, 7, 11, 15};
	int arrIn2[] = {3,2,4};
	int arrIn3[] = {0,4,3,0};

	int *arrOut = twoSum(arrIn,4,9);
	int *arrOut2 = twoSum(arrIn2,3,6);
	int *arrOut3 = twoSum(arrIn3,4,0);

	printf("arrOut = [%d, %d] \n",arrOut[0], arrOut[1]);
	printf("arrOut = [%d, %d] \n",arrOut2[0], arrOut2[1]);
	printf("arrOut = [%d, %d] \n",arrOut3[0], arrOut3[1]);

	return;
	
}
