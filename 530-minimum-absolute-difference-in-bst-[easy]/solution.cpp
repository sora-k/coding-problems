// 4/16/17 10:23PM - 12:30AM (stuck)
// around 4 hours then got stuck
//TODO: took too long!!
//            study iterative solution
#include <limits.h>
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
    int getMinimumDifference(TreeNode* root) {
 
        int left, right, curr;
      
        if(root == NULL)
            return INT_MAX;

        left         = getMinimumDifference(root->left);
        curr         = abs(prev_node_val - root->val);
        prev_node_val= root->val;
        right        = getMinimumDifference(root->right);
       
        int result   = left  < curr   ? left : curr;
        result         = right < result ? right: result;

        return result;
    }
private:
        int prev_node_val = INT_MAX;
};
 