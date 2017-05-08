//started 2/20/17 11:27PM - 11:33PM



// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
   int guessNumber(int n) {
     
     int l = 1;
     int r = n;

     while(l <= r){

       int middle = l + (r - l) / 2;
       int g      = guess(middle);

       if(g == 0){
           return middle;
       }
       if(g == 1)
          l = middle + 1;
       else
          r = middle - 1;
     }
     return -2;    
   }
};
