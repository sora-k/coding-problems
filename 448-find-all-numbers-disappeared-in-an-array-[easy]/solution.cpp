 
//448. Find All Numbers Disappeared in an Array
// started 4/6/17 8:40AM - 8:48AM
//                9:00AM - 9:24AM
//                9:34AM - 9:54AM
/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 
Find all the elements of [1, n] inclusive that do not appear in this array.
 
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 
Example:
 
Input:
[4,3,2,7,8,2,3,1]
 
Output:
[5,6]
*/
 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       
        vector<int> result;
       
        int current, tmp, current_ind;
        for(int i = 0; i < nums.size(); ++i){//sort elements in array to their corresponding indices
             current = nums[i];
             current_ind = current - 1;
             while(current_ind != i && nums[current_ind] != current){
                 tmp               = nums[current - 1];
                 nums[current_ind] = current;
                 nums[i]           = tmp;
 
                 current_ind       = tmp - 1;
                 current           = tmp;
             }
        }
        for(int i = 0; i < nums.size(); ++i){//get the missing elements
           current_ind = nums[i] - 1;
           if(current_ind != i){
              result.push_back(i + 1);
           }
        }
        return result;
    }
};
 
/*
[1]
[2,1]
[4,3,2,7,8,2,3,1]
[5,1,3,3,2,4]
*/