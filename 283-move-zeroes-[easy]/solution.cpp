//started 2/9/17 7:58PM - 8:22PM

class Solution {
public:
   void moveZeroes(vector<int>& nums) {
       
     std::vector<int>::iterator it, start;
     start = nums.end();
 
     for(it = nums.begin(); it != nums.end(); ++it){
         if(*it == 0 && start == nums.end()){
              start = it;
         }
         if(*it != 0 && start != nums.end()){
             *start = *it ^ *start;
             *it    = *it ^ *start;
             *start = *it ^ *start;

             start++;
         }
     }
   }
};
