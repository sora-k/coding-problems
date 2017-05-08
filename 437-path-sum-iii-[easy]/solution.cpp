//path sum III
//started 3/19/17 12:53PM - 1:24PM
//				  3:29PM  - 3:41PM		
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// TODO: realize the efficient solution quicker!! Too many mistakes!! 
// TODO: go back and understand the optimized solution

// more efficient solution - based on Two Sum, using hash
// runtime O(N)
class Solution {
public:
	int helper(TreeNode* node, int current_sum, int target_sum){

		int result = 0;

		if(node == NULL)
			return 0;

		current_sum = current_sum + node->val;

		if(lvl_sum_map_.find(current_sum - target_sum) != lvl_sum_map_.end())
			result = result + lvl_sum_map_[current_sum - target_sum];

		if(lvl_sum_map_.find(current_sum) != lvl_sum_map_.end())
			lvl_sum_map_[current_sum]++;
		else
			lvl_sum_map_.insert({current_sum, 1});

		result = result + helper(node->left, current_sum, target_sum) + helper(node->right, current_sum, target_sum);
        
		lvl_sum_map_[current_sum]--;

		return result;
	}
    int pathSum(TreeNode* root, int sum) { 
    	
    	lvl_sum_map_.insert({0, 1});	// <-- important initialization condition

    	return helper(root, 0, sum);
    }
private:
	unordered_map<int,int> lvl_sum_map_;
};
/*

[10,5,-3,3,2,null,11,3,-2,null,1]
8
[0,1,1]
1
[1,null,2,null,3,null,4,null,5]
3
[1,-2,-3,1,3,-2,null,-1]
2
[1,-2,-3]
-1
*/
/*
class Solution {
public:
    int pathSum(TreeNode* root, int sum) { // runtime O(n(log(n) + log(n))), space O(2log(n)) - call stack + nodes val

    	int result = 0;

    	if(root == NULL)
    		return 0;

    	lvl_sum_.push_back(root->val);
    	
    	vector<int>::iterator it;
    	for(it = lvl_sum_.begin(); it != lvl_sum_.end(); ++it){		// O(log(n))
    		if(it != lvl_sum_.end() - 1){							//increment prev sum
    			*it = *it + root->val;
    		}
    		result = (*it == sum) ? result + 1 : result;			//increment result if sum matches
    	}
   
    	result = result + pathSum(root->left, sum) + pathSum(root->right, sum);
    	
    	for(it = lvl_sum_.begin(); it != lvl_sum_.end() - 1; ++it){	// O(log(n))
    		*it = *it - root->val;									//clean up 
    	}
    	lvl_sum_.pop_back();
    
    	return result;
    }
private:
	vector<int> lvl_sum_;
};
*/