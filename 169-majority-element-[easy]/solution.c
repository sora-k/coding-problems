
// started 11/29/16 (paper solution) 8:58 - 9:03PM
//		   12/4/16  (coding) 9:47PM - 9:53PM

// NOTE: redo! not at the top! should be more efficient
// NOTE: re-implement quick sort, took way too long!! -> take into account repeated elements -> keep track of the pivot's location
#include <stdlib.h>

int partition(int *arr, int l, int r){
    
    int size = (r - l) + 1;
    
    if(size < 2){
        return -1;
    }
	int pivot = arr[(rand() % size) + l];

	while(l <= r){
		while(arr[l] < pivot) l++;
		while(arr[r] > pivot) r--;
		
		if(l <= r){
		    int tmp = arr[l];
		    arr[l] = arr[r];
		    arr[r] = tmp;
		    
		    l++;
		    r--;
		}
	
	}
	return l;
}
void quick_sort(int *arr, int left,int right){
    
	int pivot = partition(arr,left,right);
    
    if(pivot == -1){
        return;
    }
    
    //NOTE: one of the sides has to include the pivot
    quick_sort(arr,left,pivot - 1);
    quick_sort(arr,pivot, right);
    
}
int majorityElement(int* nums, int numsSize) {
    
    int result;
    int targetCnt = numsSize/2;
    int currCnt = 1;
    int curElement;

    quick_sort(nums,0,numsSize - 1);
    curElement = nums[0];

    int i;
    for(i=1; i < numsSize; i++){
        if(curElement == nums[i]){
        	currCnt++;
        }else{
        	curElement = nums[i];
        	currCnt = 1;
        }
        if(currCnt > targetCnt){
        	break;
        }
    }
    
    return curElement;
}

/*
[2,5,1]
[1]
[2,1]
[2,2]
[1,2]
[4,4,4]
[4,4,4,4]
[5,4,3,2,1]
[6,5,4,3,2,1]
[3,3,3,5,2,1]
[5,5,5,5,5,1]
[5,5,5,5,5,1,2]
*/