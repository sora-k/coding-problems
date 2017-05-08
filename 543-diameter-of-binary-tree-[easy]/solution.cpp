// started 4/22/17 12:26AM - 12:30AM
//		   4/22/17  5:44PM - 6:02PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        	
    	int diameter = 0;

    	diameter_of_binary_tree_helper(root, &diameter);

    	return diameter;

    }
private:
	int diameter_of_binary_tree_helper(TreeNode* root, int* diameter){

		if(root == NULL)
			return 0 

		int left  = diameter_of_binary_tree_helper(root->left, diameter);
		int right = diameter_of_binary_tree_helper(root->right,diameter);
		int max   = left > right ? left : right;
		*diameter = *diameter > (left + right) ? *diameter : (left + right);

		return max + 1;
	}
};

/*
[]
[null]
[1]
[1,2,3,4,5]
[2,3,3,3,3,null,null,3,null,null,3,3,null,3,null,3,null,3]
*/