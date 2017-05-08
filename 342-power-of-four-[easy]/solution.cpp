//started 2/16/17 11:55PM - 12:21AM (stuck with one line solution)
//                  2/17/17  5:19PM - 5:46PM
#include <math.h>
#include <limits>

// stupid no loop solution
class Solution {
public:
   bool isPowerOfFour(int num) { //check if power of two and in binary form, the '1' digits are in even positions.
       return (num > 0) && (num & (num - 1)) == 0 && (num & 0x55555555) == num);
   }
};

/*
// not posiible to solve with out loop/recursion?
// because 4 is not prime
// O(log4(num))
class Solution {
public:
   bool isPowerOfFour(int num) {
      
      while(num > 0){
                      if(num % 4 == 0)
                              num = num / 4;
                      else
                              break;
      }
      return num == 1;

   }
};
*/