// 12/18/16 4:47PM - 5:30PM , 6:00PM - 6:14PM
// 12/19/16 7:00AM - 8:00AM, 10:11PM - 11:00PM
// 12/20/16 6:00PM - 7:16PM

//TODO: implement hash solution!
//      took too long!!
#include <limit.h>

int power(int base, int ex){
    
    int result = base;
    
    if(ex == 0){
        return 1;
    }
    if(ex == 1){
        return result;
    }
    while(ex > 1){
        result = result * base;
        ex = ex - 1;
    }
    return result;
}
int sumOp(int n){
    
    int result = 0;
    
    while(n > 0){
        result = result +  power(n % 10, 2);
        n = n / 10;
    }
    return result;
}

bool isHappy(int n) {
    
    int slow = n;
    int fast = n;
    
    do{
        slow = sumOp(slow);
        fast = sumOp(fast);
        fast = sumOp(fast);

        if(slow == 1){
            return true;
        }

    }while(slow != fast);

    return false;
}

/*
1
2
3
4
5
6
7
8
9
*/