//started 2/8/17 11:53PM - 12:00 AM -->NOT DONE STUCK? (read the problem again)
//started 2/9/17  7:15PM - 7:31PM

class Solution {
public:
   int missingNumber(vector<int>& nums) {
    
            int size = nums.size() + 1;
            bool arr_found[size];
            std::vector<int>::iterator it;
            int i;
            
            for(i = 0; i < size; i++){
                    arr_found[i] = false;
            }
           for(it = nums.begin(); it != nums.end(); ++it){
                   if(*it < size){
                           arr_found[*it] = true;
                   }
           }
           for(i = 0; i < size; i++){
                   if(arr_found[i] == false){
                           return i;
                   }
           }
           return i;
   }
};

/*
[]
[0,1,2,8,6,7]
[1,0]
[9,0]
[0]
[0,1,2,3,5,6]
[0,1,2,3,5,6,7]
[0,1,2,4,5,6,7,8]
[0,1,2,3,4,5]
[0,1,2,3]
*/