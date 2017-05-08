//started 4/24/17 10:28AM - 10:50AM
// TODO: study faster solution
 
bool compare_func(int i, int j) {return i < j;}
 
class Solution { //O(nlogn)
public:
    int arrayPairSum(vector<int>& nums) {
       
        int result = 0;
 
        std::sort(nums.begin(), nums.end(), compare_func);
 
        for(int i = 0; i < nums.size(); i += 2)
               result += nums[i];
 
        return result;
    }
};