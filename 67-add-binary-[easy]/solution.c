
//started 11/20/16 12:39 am - 1:40am
#include <stdio.h>

char * generate_bin_str_from_reverse_int_bin_arr(int *arr, int size){
    
	int resultSize = size + 1;
	char *result = (char *)malloc(sizeof(char)*(resultSize));
	int i,j;
	for(i = 0, j = resultSize - 2; i < size; i++,j--){
		result[j] = arr[i] + '0';
	}
	result[resultSize - 1] = '\0';
	return result;

}
int str_len(char *s){

	int count = 0;
	while(*s != NULL){
		count++;
		s++;
	}
	return count;

}
char* addBinary(char* a, char* b) {
    
    char *result;
    char aLen = str_len(a);
    char bLen = str_len(b);
    
    if(aLen == 0 && bLen == 0){
        result = (char *)malloc(sizeof(char)*2);
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    
    int resultArr[aLen + bLen];
    int resultIn = 0;
    int i,j,aNum,bNum;
    int carry = 0;
    for( i = aLen - 1, j = bLen - 1; i >= 0; i--){
		aNum = a[i] - '0';    	
		aNum += carry;

    	if(j >= 0){
   			bNum = b[j] - '0';
   			aNum += bNum;
   			j--;
    	}
    	if(aNum == 1){
    	    carry = 0;
    	}
		if(aNum == 2){
			aNum = 0;
			carry = 1;
		}
		if(aNum == 3){
			aNum = 1;
			carry = 1;
		}
		resultArr[resultIn] = aNum;
    	resultIn++;
    }
    for( ; j >= 0; j--){
    	bNum = b[j] - '0';
    	bNum += carry;
    	if(bNum == 2){
			bNum = 0;
			carry = 1;
		}else{
		    carry = 0;
		}
		resultArr[resultIn] = bNum;
    	resultIn++;
    }
    if(carry != 0){
        resultArr[resultIn] = carry;
        resultIn++;
    }
    result = generate_bin_str_from_reverse_int_bin_arr(resultArr, resultIn);
    return result;
    
}