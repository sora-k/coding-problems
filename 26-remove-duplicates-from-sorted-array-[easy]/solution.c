#include <stdio.h>
// started 11/16/16 8:56 pm -> 11:09 pm
// Note: to self, improve run time (utilize binary search? , read other people's answers), write explanation on how freeInd is kept track of and cover case -> [1,2,2,3,4,5,5,6]

int removeDuplicates(int* nums, int numsSize) {
    
    if(numsSize == 0){
    	return numsSize;
    }

    int prev = nums[0];
    int count = 1;
    int freeInd = -1;
    int i;
    for(i = 1; i < numsSize; i++){
    	int curr = nums[i];

    	if(curr != prev){
    		count++;
			if(freeInd != -1){
				nums[freeInd] = curr;
				nums[i] = prev;
				freeInd++;
			}    		
			prev = curr;			
    	}else{
    		freeInd = (freeInd == -1) ? i : freeInd;
    	}
    }
    return count;
}

/*
[]
[1]
[1,2,3]
[1,2,3,4]
[1,2,2,3,3]
[1,2,2,3,4,5,5,6]
[1,1,2,3,4,4,5,6,7,7,9]
*/