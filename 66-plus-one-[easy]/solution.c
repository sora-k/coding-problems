
//started 11/20/16 12:13 am - 12:32 am
#include <stdio.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    int *result; 
    int resultSize;
    int i; int carry = 0;
    int firstDigit = 1;

    if(digitsSize == 0){
    	int tmp[1];
    	tmp[0] = 0;
    	digits = &tmp;
    	digitsSize = 1;	
    }
    for(i = digitsSize - 1; i >= 0; i--){
    	int num = digits[i];
    	num += carry;

    	if(firstDigit == 1){
    		num += 1;
    		firstDigit = 0;
    	}
    	if(num > 9){
    		carry = num / 10;
    		num = num % 10;
    	}else{
    		carry = 0;
    	}
    	digits[i] = num;
    }
    resultSize = (carry != 0) ? 1 + digitsSize : digitsSize;
    int end = (carry != 0) ? 1 : 0;
    result = (int *)malloc(sizeof(int) * resultSize);

    int k = digitsSize - 1;
    for(i = resultSize - 1; i >= end; i--){
    	result[i] = digits[k];
    	k--;
    }
    if(carry != 0){
    	result[0] = carry;
    }

    *returnSize = resultSize; 
    return result;
}
