// 11/26/16 (planning) 1:31PM - 1:56PM
// 			(coding) 7:00PM - 8:12PM
#include <stdio.h>
#include <stdlib.h>
/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// iterative solution
struct Node{
	void *val;
	struct Node *next;
	struct Node *prev;
};
struct ListNode_{
	struct Node *head;
	struct Node *last;
	int count;
};
struct Node * init_node(struct Node *next, struct Node *prev, void *val){

	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->val = val;
	node->next = next;
	node->prev = prev;

	return node;
}
struct ListNode_ * init_list(void *head, void *last, int count){

	struct ListNode_ *ls = (struct ListNode_ *)malloc(sizeof(struct ListNode_));
	ls->head = head;
	ls->last = last;
	ls->count= count;

	return ls;
}
void push_item_to_ls(struct ListNode_ *ls, void *item){

	struct Node *node = init_node(NULL,NULL,item);

	if(ls->head == NULL){
		ls->head = node;
		ls->last = node;
		ls->count = 1;
	}else{
		node->prev = ls->last;
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
int * int_array_from_list_of_tree_node(struct ListNode_ *ls){

	int size = ls->count;
	int *result = (int *)malloc(sizeof(int) * size);

	struct Node *conductor = ls->head;
	int i;
	for(i = 0;  i < size; i++){
		struct TreeNode *treeNode = (struct TreeNode *)conductor->val;
		result[i] = treeNode->val;

		conductor = conductor->next;
	}
	return result;
}
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
 	
 	int **result;

 	if(root == NULL){
 		return NULL;
 	}

 	struct ListNode_ *listOfLvls = init_list(NULL,NULL,0);
 	struct ListNode_ *curLvl = init_list(NULL,NULL,0);
 	push_item_to_ls(curLvl,root);
 	push_item_to_ls(listOfLvls,curLvl);
    
    while((curLvl->count > 0)){
    	curLvl = construct_nxt_tree_lvl_given_lvl(curLvl);
    	push_item_to_ls(listOfLvls,curLvl);
    }

    int size = (listOfLvls->count) - 1;
    result = (int **)malloc(sizeof(int *) * size);
    *columnSizes = (int *)malloc(sizeof(int) * size);
    *returnSize = size;

    struct Node *conductor = listOfLvls->last->prev;
    int i;
    for(i = 0; i < size; i++){
    	curLvl = (struct ListNode_ *)conductor->val;
    	result[i] = int_array_from_list_of_tree_node(curLvl);
    	(*columnSizes)[i] = curLvl->count;
        
        free_list(curLvl);
    	conductor = conductor->prev;
    }
    free(listOfLvls);
    return result;
}
/*
[3,9,20,null,null,15,7]
[]
[null]
[1,2,3,4]
[1,2,3,4,5,6,7,8]
*/