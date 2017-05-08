//started 2/7/17 9:18PM - 9:44PM

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
   vector<string> binaryTreePaths(TreeNode* root) {
       
       vector<string> result;

       crawler(root, "", result);

       return result;

   }
   void crawler(TreeNode* root, string curStr, vector<string>& resultVec){

           if(root == NULL){
                   return;
           }
           string val = std::to_string(root->val);
           curStr     = (curStr == "") ? val : curStr + "->" + val;

           if(root->left == NULL && root->right == NULL){ //leaf node
                   resultVec.push_back(curStr);
           }else{
                   crawler(root->left,curStr,resultVec);
                   crawler(root->right,curStr,resultVec);
           }
   }
};

/*
[]
[1]
[1,2,3,4,5]
*/
