// 11/26/16 11:11PM - 11:30PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//NOTE: leaf node are nodes without children!
int minDepth(struct TreeNode* root) {
    
    if(root == NULL){
    	return 0;
    }else{

    	int depthL = minDepth(root->left) + 1;
    	int depthR = minDepth(root->right) + 1;
    	int result;
    	
    	if(root->left != NULL && root->right == NULL ||root->left == NULL && root->right != NULL){
    		result = (root->left == NULL) ? depthR : depthL;
    	}else{
    		result = (depthL < depthR) ? depthL : depthR;
		}
    	return result;
    }

}

/*
[]
[1]
[1,2]
[1,2,3,4]
[1,2,3,4,5]
[1,2,3,4,null,6,7,8,9,null,null,10,null,null,10,null,11,12]
*/

