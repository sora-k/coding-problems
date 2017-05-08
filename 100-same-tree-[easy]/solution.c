#include <stdio.h>
// 11/22/16 10:00pm -> 10:15pm planning
// 11/24/16 11:03pm	-> 11:09pm coding
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    
    if(p == NULL && q == NULL){
    	return true;
    }
    if(p == NULL && q != NULL || p != NULL && q == NULL){
    	return false;
    }
    bool result = true;

    result &= (p->val) == (q->val);
    result &= isSameTree(p->left,q->left);
    result &= isSameTree(p->right,q->right);
    return result;

}
/*
[null]
[null]
[1,2,3,4,6]
[1,2,3,4,6]
[1,2,3,4,6]
[1,2,3,4,null]
*/