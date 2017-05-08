// started 11/26/16 8:32PM - 9:34PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int is_balanced(struct TreeNode* root, bool *balanced){

	int result = 0;

	if(root == NULL){
		return result;
	}else{
		bool balancedL = true;
		bool balancedR = true;
		int leftH = is_balanced(root->left, &balancedL) + 1;
		int rightH = is_balanced(root->right, &balancedR) + 1;
		result = (leftH > rightH) ? leftH : rightH;

		int dif = leftH - rightH;
    	dif = (dif < 0) ? dif * -1 : dif;
    	*balanced = ((dif > 1 == false) && (balancedL == true && balancedR == true))? true : false;
    
	    return result;
	}

}
bool isBalanced(struct TreeNode* root) {
    
    if(root == NULL){
    	return true;
    }
    bool result = true;
   	is_balanced(root,&result);

    return result;
}

/*
[]
[null]
[1]
[1,2]
[1,2,3]
[1,2,3,null,4]
[1,2,3,null,null,4,5,null,null,null,6]
[1,2,null,3,null,null,4]
[1,2,2,3,null,null,3,4,null,null,4]
[1,2,3,4,5,null,6,7,null,null,null,null,8]
*/