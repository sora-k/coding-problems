// started 2/7/17 8:49AM - 9:59AM
// TODO: clean up code
//       took too long!
/*
 Computation of lowest common ancestors may be useful, for instance, as part of a procedure for determining the distance between pairs of nodes in a tree: the distance from v to w can be computed as the distance from the root to v, plus the distance from the root to w, minus twice the distance from the root to their lowest common ancestor
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include <stack>
#include <cmath>
 
using std::cout;
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
                               
        TreeNode* result = NULL;
        bool found_both;

        found_both  = findNodeStoreAncsToStack(root,p,stack_p_);
        found_both &= findNodeStoreAncsToStack(root,q,stack_q_);                                            
       
        if(found_both == true){
            int size_dif = stack_q_.size() - stack_p_.size();
            int cnt = std::abs(size_dif);

            if(size_dif < 0){
                popStackGivenCnt(stack_p_,cnt);
            }else{
                popStackGivenCnt(stack_q_,cnt);
            }
            while(stack_p_.top() != stack_q_.top()){
                stack_p_.pop();
                stack_q_.pop();
            }
            result = stack_p_.top();
        }
        return result;
    }
    bool findNodeStoreAncsToStack(TreeNode* root, TreeNode* target, std::stack<TreeNode*> &stack_tar){

        int val = target->val;

        while(root != NULL){
            stack_tar.push(root);
            if(target == root){
                return true;
            }else{
                if(val > root->val){
                    root = root->right;
                }else{
                    root = root->left;
                }
            }
        }
        return false;
    }
    bool popStackGivenCnt(std::stack<TreeNode*> &stack_tar, int cnt){

        if(stack_tar.size() < cnt){
            return false;
        }
        for(int i = 0; i < cnt; i++){
            stack_tar.pop();
        }
        return true;

    }
private:
    std::stack<TreeNode *> stack_p_;
    std::stack<TreeNode *> stack_q_;
};
/*
[2,1,3]
*/