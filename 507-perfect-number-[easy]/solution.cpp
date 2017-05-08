//started 4/21/17 1:02PM - 1:28PM
 
class Solution {
public:
    bool checkPerfectNumber(int num) {
      if(num <= 1)
          return false;
     
      int di = 2, quo, sum = 1;
     
      while(di*di <= num){
         if((num % di) == 0){
             quo    = num / di;
             sum    = sum + di + quo;
         }
         di++;
      }
      return sum == num;
    }
};