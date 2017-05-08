/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
// iterative (breadth first) solution
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
       
        if(root == NULL){
            return NULL;
        }
       
        std::queue<TreeNode *> q;
        q.push(root);
       
        while(q.empty() == false){
            TreeNode *node = q.front();
            q.pop();
       
            SwapNodes(&(node->left),&(node->right));
           
            if(node->left != NULL){
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }
        }
       
        return root;
    }
private:
    void SwapNodes(struct TreeNode **left, struct TreeNode **right){
       
        struct TreeNode *tmp = *left;
        *left  = *right;
        *right = tmp;
       
    }
};
// recursive solution
/*
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
       
        if(root == NULL){
            return NULL;
        }
        SwapNodes(&(root->left), &(root->right));
       
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
private:
    void SwapNodes(struct TreeNode **left, struct TreeNode **right){
       
        struct TreeNode *tmp = *left;
        *left  = *right;
        *right = tmp;
       
    }
};
*/
/*
[4,2,7,1,3,6,9]
[2,3,null,1]
*/
 