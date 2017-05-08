// started 1/20/17 10:59PM - 12:00AM
#include <stdio.h>
#include <stdlib.h>

//TODO: implement hash table - self balancing binary tree, search() and insert() should take O(log(n))
//NOTE: didn't need to do bin_search!!! , could just traverse through the sorted arry for duplicates, faster!

bool bin_search(int *arr, int start, int end, int target){

	int l = start;
	int r = end;

	while(l <= r){

		int m = (r + l) / 2;
        
		if(arr[m] == target){
			return true;
		}
		if(target < arr[m]){
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	
    return false;
}
void swap(int *x, int *y){
	
	if(*x == *y) 
	    return;
	
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;

}
void quick_sort(int *arr, int start, int end){

	int piv = partition(arr, start, end);
	
	if(start < piv - 1){
		quick_sort(arr, start, piv - 1);
	}
	if(end > piv){
		quick_sort(arr, piv, end);
	}

}
int partition(int *arr, int start, int end){

	if(start >= end){
		return;
	}

	int cnt = (end - start) + 1;
	int piv = rand() % cnt  + start;
	int pivE = arr[piv];

	while(start <= end){
		while(arr[start] < pivE){
			start++;
		}
		while(arr[end] > pivE){
			end--;
		}
		if(start <= end){
			swap(&(arr[start]), &(arr[end]));
			start++;
			end--;
		}
	}
	return start;

}
// without bin search ! think !
bool containsDuplicate(int* nums, int numsSize) {
    
    time_t t;
 	srand((unsigned) time(&t));
    
    quick_sort(nums,0,numsSize - 1);
    
    for(int i = 0; i < numsSize - 1; i++){
        if(nums[i] == nums[i + 1]){
        	return true;
        }
    }
    return false; 
}
/*
bool containsDuplicate(int* nums, int numsSize) {
    
    time_t t;
 	srand((unsigned) time(&t));
    
    quick_sort(nums,0,numsSize - 1);
    
    for(int i = 0; i < numsSize; i++){
        
        bool result = bin_search(nums,i + 1,numsSize - 1,nums[i]); 
        
        if(result == true){
            return result;
        }
        
    }
    return false; 
}
*/

/*
[2]
[3,2]
[4,3,2]
[1,2,3,2,1]
[5,4,3,2,1,0]
[2,2,2,2,2]
[2,2,2,2,2,2]
*/