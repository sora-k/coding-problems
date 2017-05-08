// 2/2/17 started 8:45AM - 9:33AM
#include <cmath>  
 
class Solution {
public:
    bool isPowerOfTwo(int n) {
       
        int count = 0;
       
        if(n < 0){
            return false;
        }
        while(n != 0){
            n = n & (n - 1);
            count++;
           
            if(count > 1){
                break;
            }
        }
        return (count == 1);
    }
};
 
/*
0
1
4
5
6
8
16
17
18
19
20
21
22
23
24
25
32
64
-2147483648
-2
-6
-7
-8
-9
-10
-16
-32
 
*/