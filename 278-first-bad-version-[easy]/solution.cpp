//started 2/12/17 2:14AM - 2:29AM (no clear solution, read the problem wrong)
//started 2/12/17 10:50AM - 11:40AM (timelimit exceed)
#include <limits>

// optimal solution, proof by induction!

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
   int firstBadVersion(int n) {
     
       if(n < 1){
          return n;
       }

       int left = 1;
       int right = n;

       while(left < right){
           int middle = left + (right - left) / 2;

           if(isBadVersion(middle) == true){
              right = middle;
           }else{
              left = middle + 1;
           }
       }
       return left;
   }
};

// time limit exceed and overflow problem when calculating middle
/* 
class Solution {
public:
   int firstBadVersion(int n) {
       
       if(n < 1){
               return n;
       }

       int left  = 1;
       int right = n;

       while(left <= right){
               
               int middle = (left + right) / 2;

               bool isBadLeft = (0 < middle - 1) ? isBadVersion(middle - 1) : false;
               bool isBadCur  = isBadVersion(middle);

               if(isBadLeft == false && isBadCur == true){
                       return middle;
               }
               if(isBadCur == false){
                       left  = middle + 1;
               }else{
                       right = middle - 1;
               }
       }
   }
};
*/
