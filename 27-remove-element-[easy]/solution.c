#include <stdio.h>

// started 11/16/16 11:18pm - (inactive 12:00 am -> 8am) - finish 8:58 am 11/17/16
// Note to self -> improve the efficiency! beating no one!, read other solution
int removeElement(int* nums, int numsSize, int val) {
	
	if(numsSize == 0){
		return numsSize;
	}

	int freeInd = -1;
	int count = 0;
	int i;
	for(i = 0; i < numsSize; i++){
		int num = nums[i];
		
		if(num != val){
			if(freeInd != -1){
				nums[i] = nums[freeInd];
				nums[freeInd] = num;
				freeInd++;
			}
			count++;
		}else{
			freeInd = (freeInd == -1) ? i : freeInd;
		}
	}
	return count;
}
/*
[2,1,1,1,1,1,1,1]
2
[1,2,1,1,1,1,1,2]
2
[2]
2
[1,1,1,1,1,1]
1
[1,2,3,4,5]
9
[]
3
[3,2,1,0,3]
3
*/