// To Run, paste this in LeetCode
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

