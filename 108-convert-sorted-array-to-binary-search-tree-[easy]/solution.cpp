//started 4/23/17 6:17PM - 6:33PM (stuck)
//				  7:32PM - 8:07PM

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
[1,2,3,4,5,6,7,8,9]
 0,1,2,3,4,5,6,7,8 

		   [1,2,3,4, |  5, | 6,7,8,9]							mid = 8 - (8 - 0) / 2 = 4
 		    0,1,2,3, |  4, | 5,6,7,8 

	  [1,2, | 3, | 4, 		6,7, | 8, | 9]						mid = 3 - (3 - 0) / 2 = 2
 	   0,1, | 2, | 3, 	    5,6, | 7, | 8 						mid = 8 - (8 - 5) / 2 = 7

[1, | 2, | 		 | 4, |	     	 6, | 7, | 	    | 9 |]			mid = 1 - (1 - 0) / 2 = 1
 0,	  1, 		   3, 			 5,   6, 		  8 			mid = 6 - (6 - 5) / 2 = 6

| 1, |						  | 6 |
  0								5

*/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return sorted_array_to_bst_helper(nums, 0, nums.size() - 1);

    }
private:
	TreeNode* sorted_array_to_bst_helper(vector<int>& nums, int start, int end){

		TreeNode* new_node = NULL;

		if(start > end)
			return new_node;

		int mid   = end - (end - start) / 2;

		new_node = new TreeNode(nums[mid]); 

		new_node->left = sorted_array_to_bst_helper(nums, start, mid - 1);

		new_node->right= sorted_array_to_bst_helper(nums, mid + 1, end);

		return new_node;
	}

};


/*
[]
[1]
[1,2]
[1,2,3]
[1,2,3,4]
[1,2,3,4,5]
[1,2,3,4,5,6]
[1,2,3,4,5,6,7]
[1,2,3,4,5,6,7,8]
[1,2,3,4,5,6,7,8,9]
[1,2,3,4,5,6,7,8,9, 10]
*/