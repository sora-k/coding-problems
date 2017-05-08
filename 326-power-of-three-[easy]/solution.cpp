//started 2/16/17 9:23PM - 9:58PM (naive solution)


//TODO: implement "mathematics" solution
//1. base conversion 

/*
using std::vector;
class Solution {                        //O(2*log3(n)) - time, O(log3(n)) - space
public:
   bool isPowerOfThree(int n) { 

       vector<char> base_3 = integerToString(n, 3);

       vector<char>::iterator it;
       int nonZeroCnt = 0; char c;
       for(it = base_3.begin(); it != base_3.end(); ++it){
           nonZeroCnt = (*it != '0') ? nonZeroCnt + 1: nonZeroCnt;
           c          = (*it != '0') ? *it : c;
       }
       return c == '1' && nonZeroCnt == 1;
   }
   vector<char> integerToString(int n, int base){

       vector<char> result;
       int curr = 1;

       while(n > 0){
           int remainder = n % base;
           n = n / base;
           result.push_back('0' + remainder);
       }

       return result;
   }
};
*/
//2. mathematics - not implemented
/*
class Solution {
public:
   bool isPowerOfThree(int n) {
       // n = 3^i
       // log(n) = i * log(3)
       // i      = log(n) / log(3)

       //return isInteger(log(n) / log(3));
   
   }
};
*/
//3. integer limitations
#include <math.h>
#include <limits.h>

class Solution {
public:
   Solution(){

       // 3^i        = max_int
       // i * log(3) = log(max_int)
       // i          = log(max_int) / log(3)
       // 3^i --> max power of 3

       int i      = log2(std::numeric_limits<int>::max()) / log2(3);
       max_pow_3_ = pow(3, i);

   }
   bool isPowerOfThree(int n) {

       return n > 0 && max_pow_3_ % n == 0;
   
   }
private:
   int max_pow_3_ = 0;
};
//4. naive solution O(log3(n))
/*
class Solution {
public:
   bool isPowerOfThree(int n) {

       while(n > 1){
               if(n % 3 == 0){
                       n = n / 3;
               }else{
                       break;
               }
       }
       return n == 1;
   
   }
};
*/
/*
0
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
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
26
27
28
29
30
27
*/