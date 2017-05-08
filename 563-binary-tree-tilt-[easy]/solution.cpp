// started 4/24/17 2:32PM - 2:42PM
 
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
    int findTilt(TreeNode* root) {
       
        int tilt = 0;
 
        find_tilt_helper(root, &tilt);
 
        return tilt;
    }
private:
    int find_tilt_helper(TreeNode* root, int* tilt){

        if(root == NULL)
                        return 0;

        int sum_left = find_tilt_helper(root->left, tilt);
       
        int sum_right= find_tilt_helper(root->right,tilt);

        *tilt = *tilt + abs(sum_right - sum_left);

        return sum_left + root->val + sum_right;
    }
};