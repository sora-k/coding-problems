//started 11/26/16 12:01AM - 12:30AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    
    bool result;
    
    if(root == NULL){
        return false;
    }
    if(root->left == NULL && root->right == NULL){
        result = (root->val == sum) ? true : false;
    }else{
        int newSum = (sum - root->val);
        
        if(root->left == NULL && root->right != NULL || root->left != NULL && root->right == NULL){
             struct TreeNode *node = (root->left == NULL)? root->right: root->left;
             result = hasPathSum(node, newSum);
        }else{
            bool left,right = false;
            left = hasPathSum(root->left,newSum);
            
            if(left == false){ //saves computation time
                right = hasPathSum(root->right,newSum);
            }
            result = (left == true) ? left : right;
            result = (right == true) ? right : result;
        }
    }
    return result;
}

/*
[1,2]
1
[1,2]
0
[-2,null,-3]
-5
[]
1
[1]
1
[0]
1
[1,2,3,4,5]
7
[5,4,8,11,null,13,4,7,2,null,null,null,1]
22
*/