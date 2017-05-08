//started 4/24/17 11:02AM - 11:06AM
//TODO: study faster solution
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       
        int i;
        for(i = 0; i < nums.size(); ++i){
           if(nums[i] >= target)
               return i;
        }
        return i;
    }
};