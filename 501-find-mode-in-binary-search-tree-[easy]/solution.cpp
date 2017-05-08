
// 4/20/17 10:29AM – 12:00PM stuck
// 4/21/17 8:00AM   - 9:44AM
 
//TODO: too slow!!
//            study best C++ practice, Google style sheet?
//            watch out for usage of pointers!! Setting *x vs. x
//            do more recursion problems, study recursion !! be able to trace recursion code
//            if(condition)                      vs.           if(condtion);
//                do something                                      do somthing
 
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
    vector<int> findMode(TreeNode* root) {
       
        vector<int> result;
        int         max_cnt, cnt;
        TreeNode    *prev_node;
       
        if(root == NULL)
           return result;
       
        max_cnt   = 0;
        cnt       = 1;
        prev_node = NULL;
       
        in_order_walk_max_cnt(root, &prev_node, &cnt, &max_cnt);
       
        cnt       = 1;
        prev_node = NULL;  //NOTE: watch out! there's a difference b/t setting *prev_node and prev_node
                               
        in_order_walk_store_mode(root, &prev_node, &cnt, max_cnt, result);
 
       return result;
    }
private:
    void in_order_walk_max_cnt(TreeNode* root, TreeNode** prev_node, int* cnt, int* max_cnt){

        if(root == NULL)
            return;

        in_order_walk_max_cnt(root->left, prev_node, cnt, max_cnt);

        if((*prev_node) != NULL && (*prev_node)->val == root->val)
            *cnt = *cnt + 1;
        else{
            *cnt      = 1;
            *prev_node= root;
        }
        *max_cnt = *max_cnt < *cnt ? *cnt : *max_cnt;

        in_order_walk_max_cnt(root->right, prev_node, cnt, max_cnt);
    }
    void in_order_walk_store_mode(TreeNode* root, TreeNode** prev_node, int* cnt, int max_cnt, vector<int>& result){

        if(root == NULL)
            return;

        in_order_walk_store_mode(root->left, prev_node, cnt, max_cnt, result);

        if((*prev_node) != NULL && (*prev_node)->val == root->val)
            *cnt = *cnt + 1;
        else{
            *cnt      = 1;
            *prev_node= root;
        }
       
        if(*cnt == max_cnt)
            result.push_back(root->val);
           

        in_order_walk_store_mode(root->right, prev_node, cnt, max_cnt, result);

    }
};
 
/*
[1,null,2,2]
[6,2,8,0,4,7,9,null,null,2,6]
[6,6,6,4,6,null,8,null,null,null,null,6,9]
*/