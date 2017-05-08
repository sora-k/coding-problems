//  iterative solution: 
//			11/25/16 (planning) 1:53AM -> 1:59AM 
//		    11/25/16 (coding) 5:00PM -> 6:00 PM
// 	recursive solution:
//			6:00 PM-> 6:20 PM 
// NOTE: figureout why recursive solution is faster? less overhead??
/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// recursive solution
int maxDepth(struct TreeNode* root) {
	
	int result = 0;

	if(root == NULL){
		return result;
	}else{
		int cntLeft = maxDepth(root->left) + 1;
		int cntRight = maxDepth(root->right) + 1;

		result = (cntLeft > cntRight)? cntLeft : cntRight;
	}
	return result;

}
// iterative solution
/*
struct Node{
	struct TreeNode *val;
	struct Node *next;
};
struct ListNode_{
	struct Node *head;
	struct Node *last;
	int count;
};
struct Node * init_node(struct Node *next, struct TreeNode *val){

	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->val = val;
	node->next = next;

	return node;
}
struct ListNode_ * init_list(struct Node *head, struct Node *last, int count){

	struct ListNode_ *ls = (struct ListNode_ *)malloc(sizeof(struct ListNode_));
	ls->head = head;
	ls->last = last;
	ls->count= count;

	return ls;
}
void push_item_to_ls(struct ListNode_ *ls, struct TreeNode *item){

	struct Node *node = init_node(NULL,item);

	if(ls->head == NULL){
		ls->head = node;
		ls->last = node;
		ls->count = 1;
	}else{
		ls->last->next = node;
		ls->last = node;
		ls->count = ls->count + 1;
	}
}
void free_list(struct ListNode_ *ls){

	struct Node *conductor = ls->head;

	while(conductor != NULL){
		conductor->val = NULL;
		struct Node *tmp = conductor;
		conductor = conductor -> next;
		free(tmp);
	}
	free(ls);
}
struct ListNode_ * construct_nxt_tree_lvl_given_lvl(struct ListNode_ *lvl){

	struct ListNode_ *newLvl = init_list(NULL,NULL,0);
	struct Node *conductor = lvl->head;

	while(conductor != NULL){
		struct TreeNode *treeNode = conductor -> val;

		if(treeNode->left != NULL){
			push_item_to_ls(newLvl, treeNode->left);
		}
		if(treeNode->right != NULL){
			push_item_to_ls(newLvl, treeNode->right);
		}
		conductor = conductor -> next;
	}
	return newLvl;
}
int maxDepth(struct TreeNode* root) {
	
	int result = 0;

	if(root == NULL){
		return result;
	}
	struct ListNode_ *curLvl = init_list(NULL,NULL,0) ;
	push_item_to_ls(curLvl,root);
	result++;

	while((curLvl->count) > 0){
		struct ListNode_ *tmp = curLvl;
		curLvl = construct_nxt_tree_lvl_given_lvl(curLvl);

		free_list(tmp);
		result = (curLvl->count) > 0 ? result + 1 : result;
	}
	return result;
}
*/
/*
[]
[1]
[1,2,3,4,5,6,7,
*/