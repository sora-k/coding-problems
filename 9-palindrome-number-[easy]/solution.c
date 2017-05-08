//started 9/11/16 - 9/12/16 Took 1 day- including sleep for 10 hours and play time on and off for 6 hours

#include <stdio.h>
#include <stdbool.h>	// compiler that supports C99 

int dig_count(int x){
    
    if(x == 0){ //Important!!
        return 1;
    }
	int count = 0;
	while(x != 0){
		count++;
		x /= 10;
	}
	return count;

}
int create_divisor(int baseNum,int multi,int ex){

    while(ex != 0){
        baseNum *= multi;
        ex--;
    }
	return baseNum;
}
bool isPalindrome(int x) {

	bool result = true;
    
	int digCnt = dig_count(x);
	int divisor = create_divisor(1,10,digCnt - 1);
	int negative = x < 0 ? 1 : 0;
	int bckX = x;
	result = negative == 1 ? false : true; //note: negative number isn't palindromic
	
	while(digCnt > 1 && negative == 0){  
		int frntDig = x / divisor;
		frntDig %= 10;
		divisor /= 10;
		int bckDig = bckX % 10;
		bckX /= 10;
       // printf("frn %d - bck %d \n",frntDig,bckDig);
		if(bckDig != frntDig){
			result = false;
			break;
		}
		digCnt -= 2;
	}

	return result;
    
}