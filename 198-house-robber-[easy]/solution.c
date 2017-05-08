// 12/15/16 (paper solution) 8:10AM - 8:36AM
// 12/18/16 (paper solution) 1:00AM - 3:00AM
// 12/18/16 (coding) 1:00PM - 1:20PM

// TODO: redo! took too long, implement O(1) solution
// O(n) memory solution
/*
int rob(int* nums, int numsSize) {
    
    int maxArr[numsSize];
    int i,j,result;
    
    for(i = numsSize - 1; i >= 0 ; i--){
       if(i == (numsSize - 1) || i == (numsSize - 2)){
           maxArr[i] = nums[i];
       }else{
           int ind1 = i + 2;
           int ind2 = i + 3;
           int num1 = (ind1 < numsSize) ? maxArr[ind1] : 0;
           int num2 = (ind2 < numsSize) ? maxArr[ind2] : 0;
           
           maxArr[i] = (num1 < num2) ? num2 + nums[i] : num1 + nums[i];
       }
    }
    int num1 = (0 < numsSize) ? maxArr[0] : 0;
    int num2 = (1 < numsSize) ? maxArr[1] : 0;

    result = (num1 < num2) ? num2 : num1;
    return result;
}
*/

// O(1) memory solution
int rob(int* nums, int numsSize) {
    //...
}
/*
[]
[1]
[1,2]
[2,1]
[4,1,2,7,5,3,1]
[1,6,1,1,1]
[1,8,1,1,9]
[1,1,8,1,1,9]
[4,6,9,0,2,4,4]
*/