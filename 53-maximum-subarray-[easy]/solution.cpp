//Need to study more!
// 4/23/17 8:11PM - 9:23PM (stuck)

//TODO: update time with the home computer solution
//TODO: study divide and conquer solution -> look up videos
//                            study how to determine runtime of recursive function //https://discuss.leetcode.com/topic/25396/c-an-clear-o-n-divide-and-conquer-solution-with-comments
//                            study dynamic programming  -> look up videos
//                              - proof for dp? will you always get the optimal solution?
 
//TODO: divide and conquer problem
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    
    }
};
 
//reduced dp soluton
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       
        int dp[nums.size()];
        int result         = nums[0];       
        int current_sum = 0;
 
        for(int i = 0; i < nums.size(); ++i){
               current_sum = current_sum + nums[i];
               result        = result > current_sum ? result : current_sum;
               current_sum = current_sum > 0 ? current_sum : 0;
        }
        return result;
    }
};
*/
// dp solution
// modify the problem from maxSubArray(A[], i, j) to maxSubArray(A[], i) where A[i] is the end element
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       
        int dp[nums.size()];
        int result = nums[0];       
        dp[0]               = nums[0];
 
        for(int i = 1; i < nums.size(); ++i){
               dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
               result= result > dp[i] ? result : dp[i];
        }
        return result;
    }
};
*/
 
// [-1]
// [1,2,-1,-2,2,1,-2,1,4,-5,4]