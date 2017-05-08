// started 3/12/17 3:45PM - 4:09PM (recursive solution)

// TODO: see if can do better!

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

// iterative solution 
class Solution {
public:
   int sumOfLeftLeaves(TreeNode* root) {
     
     int result = 0;

     queue<TreeNode*> queue_nodes;
     if(root != NULL)
        queue_nodes.push(root);
     
     TreeNode* curr_node;
     while(queue_nodes.empty() == false){

         curr_node = queue_nodes.front();
         queue_nodes.pop();

         if(curr_node->left != NULL){
             if(curr_node->left->left == NULL && curr_node->left->right == NULL)
                result += curr_node->left->val;
             else
                queue_nodes.push(curr_node->left);
         }
         if(curr_node->right != NULL){
            queue_nodes.push(curr_node->right);
         }
     }
     return result;
   }
};
// recursive solution
/*
class Solution {
public:
       int sumOfLeftLeaves(TreeNode* root, bool left){

          if(root == NULL) return 0;

      if(root -> left == NULL && root -> right == NULL && left == true)
                      return root->val;
              else
                      return sumOfLeftLeaves(root -> left, true) + sumOfLeftLeaves(root -> right, false);


       }
   int sumOfLeftLeaves(TreeNode* root) {
      
     return sumOfLeftLeaves(root, false);

   }
};
*/

/*
[3, 3, 3,3, 3, 3, 3, 4, 3,7,3,8,3,9,3]
[3, 3, 3,3, 3, 5, 3, 4, 3,7,3,8,3,9]
[3, 3, 3,3, 3, 5, 3, 4, 3,7,3,8,3]
[3, 3, 3,3, 3, 5, 3, 4, 3,7,3,8]
[3, 3, 3,3, 3, 5, 3, 4, 3,7,3]
[3, 3, 3,3, 3, 5, 3, 4, 3,3]
[3, 3, 3,3, 3, 5, 3, 4, 3]
[3, 3, 3,3, 3, 5, 3, 4, 5]
[3, 3, 3,3, 3, 5, 3, 4]
[3, 3, 3,3, 3, 3, 3, 3]
[3,9,20,null,null,15,7]
*/