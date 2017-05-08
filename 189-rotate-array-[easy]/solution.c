// 12/11/16 - 12/12/16
// (solution 1) 11:40PM - 12:05AM
// (solution 2) 12:05AM - 12:27AM

//solution 1 -> O(n) memory, O(n) time 
void rotate(int* nums, int numsSize, int k) {
    
    int i;
    int tmpArr[numsSize];
    for(i = 0; i < numsSize; i++){
    	tmpArr[i] = nums[i];
    }

    for(i = 0; i < numsSize; i++){
    	int newInd = (i + k) % numsSize;
    	nums[newInd] = tmpArr[i];
    }
}
//solution 2 -> O(1) memory, O(n) time
void rotate(int* nums, int numsSize, int k) {
	
    int count = numsSize;
    int startInd = 0;     
   
    int newInd = (startInd + k) % numsSize;
    int currE = nums[startInd];
    int desE;

    while(count > 0){
    	desE = nums[newInd];
    	nums[newInd] = currE;
    	currE = desE;
    	count--;
    	
    	if(newInd == startInd){
    	    startInd++;
    	    newInd = (startInd + k) % numsSize;
            currE = nums[startInd];
    	}else{
    	    newInd = (newInd + k) % numsSize;
    	}
    
    }
}

// solution 3 -> O(1) memory, O(n) time

void reverse(int *arr, int start, int end){

	while(start < end){
		arr[start] ^= arr[end];
		arr[end] ^= arr[start];
		arr[start] ^= arr[end];

		start++;
		end--;
	}
}
void rotate(int* nums, int numsSize, int k) {
	
	k = k % numsSize; //case in which k > numsSize! 

  	reverse(nums,0,numsSize - 1);
  	reverse(nums,0,k - 1);
  	reverse(nums,k,numsSize - 1);

}