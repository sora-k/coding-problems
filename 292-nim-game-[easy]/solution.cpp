//started 2/12/17 8:00PM - 9:00PM (learn the rules from https://www.youtube.com/watch?v=niMjxNtiuu8)

//TODO: review proof by induction

class Solution {
public:
   bool canWinNim(int n) {
       if(n % 4 == 0){
           return false;
       }else{
           return true;
       }
   }
};