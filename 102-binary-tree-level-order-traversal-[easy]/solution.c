#include <stdio.h>

// 11/25/16 (planning) 1:53AM - 1:56AM
// 			(coding) 2:00AM -> 3:18AM , (sleep) , (debugging) 8:33AM -> 9:02AM
// NOTE: make sure to understand the specs (i.e. what is being retruned), made a mistake that columnSizes points to multiple array
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
struct Node{
	struct TreeNode *val;
	struct Node *next;
};
struct ListNode_{
	struct Node *head;
	struct Node *last;
	struct ListNode_ *nextList;
	int count;
};
struct ListListNode{
	struct ListNode_ *head;
	struct ListNode_ *last;
	int count;
};
struct Node * init_node(struct Node *next, struct TreeNode *val){

	struct Node *result = (struct Node *)malloc(sizeof(struct Node));
	result->next = next;
	result->val = val;

	return result;
}
void init_list(struct ListNode_ *ls, struct Node *head, struct Node *last, int count){

	ls->head = head;
	ls->last = last;
	ls->count = count;

}
void push_item_to_list(struct ListNode_ *ls, struct TreeNode *val){

	if(ls->head == NULL){
		ls->head = init_node(NULL,val);
		ls->last = ls->head;
		ls->count = 1;
	}else{
		struct Node *newNode = init_node(NULL,val);
		ls->last->next = newNode;
		ls->last = newNode;
		ls->count = ls->count + 1;
	}

}
void free_list(struct ListNode_ *ls){

	struct Node *conductor = ls->head;
	
	while(conductor != NULL){
		struct Node *tmp = conductor;
		conductor->val = NULL;
		conductor = conductor -> next;

		free(tmp);
	}
	free(ls);

}
struct ListNode_ * construct_next_tree_lvl_given_lvl(struct ListNode_ *lvl){

	struct ListNode_ *newList = (struct ListNode_ *)malloc(sizeof(struct ListNode_));
	init_list(newList,NULL,NULL,0);

	struct Node *conductor = lvl -> head;
	while(conductor != NULL){
		struct TreeNode *treeN = conductor -> val;
		if(treeN->left != NULL){
			push_item_to_list(newList, treeN->left);
		}
		if(treeN->right != NULL){
			push_item_to_list(newList, treeN->right);
		}

		conductor = conductor -> next;
	}
	return newList;

}
int * construct_int_arr_from_ls(struct ListNode_ *ls, int *arrSize){

	int size = ls->count;
	int *result = (int *)malloc(sizeof(int) * size);

	int i;
	struct Node *conductor = ls -> head;
	for(i=0; i < size; i++){
		result[i] = conductor->val->val;
		conductor = conductor->next;
	}
	*arrSize = size;
	return result;

}
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
	
	int **result;

	if(root == NULL){
		return NULL;
	}

	struct Node *firstNode = init_node(NULL,root);
	struct ListNode_ *curLvl = (struct ListNode_ *)malloc(sizeof(struct ListNode_));
	init_list(curLvl,firstNode,firstNode,1);
	curLvl -> nextList = NULL;

	struct ListListNode *listOfLvls = (struct ListListNode *)malloc(sizeof(struct ListListNode));
	listOfLvls->head = curLvl;
	listOfLvls->last = curLvl;
	listOfLvls->count = 1;

	while((curLvl -> count) > 0){
		struct ListNode_ *nextLvl = construct_next_tree_lvl_given_lvl(curLvl);
		nextLvl->nextList = NULL;

		listOfLvls->last->nextList = nextLvl;
		listOfLvls->last = nextLvl;
		listOfLvls->count = listOfLvls->count + 1;

		curLvl = nextLvl;
	}

	int i;
	int numLvl = listOfLvls -> count - 1;
	*returnSize = numLvl;
	result = (int **)malloc(sizeof(int *) * numLvl);
	*columnSizes = (int *)malloc(sizeof(int) * numLvl);
	
	curLvl = listOfLvls -> head;
	for(i = 0; i < numLvl; i++){
	    int *size = &columnSizes[0][i];
		result[i] = construct_int_arr_from_ls(curLvl,size);
		
		struct ListNode_ *tmp = curLvl;
		curLvl = curLvl -> nextList;
	    free_list(tmp);
	}
	free(listOfLvls);

	return result;
}