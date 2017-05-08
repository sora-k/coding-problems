#include <stdio.h>
// started 11/22/16 10:15pm -> 12:00am
//		   11/23/16 7:40am -> 8:20am     //-> finished recursive solution on paper
//		   11/24/16 8:34pm -> 8:47pm	 //-> finished coding recrusive solution
//		   11/24/16 7:00pm -> 8:20pm 	 //-> draft and do research for iterative solution
//		   11/24/16 9:00pm -> 11:00pm 	 //-> finish iterative solution
//NOTE: make the recursive solution run faster! only beating 1.73% of the people
//NOTE: simplify iterative solution !! to complicated
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//iterative solution
struct Node{
	struct Node *prev;
	struct Node *next;
	struct TreeNode *val;
};
struct ListNode_{
	struct Node *head;
	struct Node *last;
	int count; 
};
struct Node * init_node(struct TreeNode *val, struct Node *prev, struct Node *next){

	struct Node *result = (struct Node *)malloc(sizeof(struct Node));
	result -> next = next;
	result -> prev = prev;
	result -> val = val;

	return result;

}
void push_element_to_list(struct TreeNode *val, struct ListNode_ *ls){

	if(ls->head == NULL){
		ls->head = init_node(val,NULL,NULL);
		ls->last = ls->head;
		ls->count = 1;
		return;
	}else{
		struct Node *prev = ls->last;
		struct Node *newNode = init_node(val, prev, NULL);

		ls->last->next = newNode;
		ls->last = newNode;
		ls->count = ls->count + 1;		
	}

}
void init_list(struct ListNode_ *ls, int count, struct Node *head, struct Node *last)
{
	ls->count = count;
	ls->head = head;
	ls->last = last;
}
void free_list(struct ListNode_ *ls){

	struct Node *head = ls -> head;

	while(head != NULL){
		struct Node *tmp = head;
        head -> val = NULL;
		head = head -> next;
		free(tmp);
	}
	free(ls);

}
bool is_list_symmetric(struct ListNode_ *ls){

	int count = ls -> count;
	bool result = true;

	struct Node *head = ls -> head;
	struct Node *last = ls -> last;

	if(count == 0){
		return true;
	}
	if(count % 2 != 0){
		return false;
	}
	while(count > 0){
		struct TreeNode *headT = head ->val;
		struct TreeNode *lastT = last ->val;
		
		struct TreeNode *headTleft = headT -> left;
		struct TreeNode *headTright = headT ->right;
		struct TreeNode *lastTleft = lastT -> left;
		struct TreeNode *lastTright = lastT -> right;

		if(headTleft == NULL && lastTright != NULL || headTleft != NULL && lastTright == NULL){
			return false;
		}
		if(headTright == NULL && lastTleft != NULL || headTright != NULL && lastTleft == NULL){
			return false;
		}
		if(headTleft != NULL && lastTright != NULL){
		    if(headTleft->val != lastTright->val){
		        return false;
		    }
		}
		if(headTright != NULL && lastTleft != NULL){
    		if(headTright->val != lastTleft->val){
    		        return false;
    		 }
		}
    	

		head = head -> next;
		last = last -> prev;
		count -= 2;
	}
	return result;
}
struct ListNode_ * generate_list_lvl_from_given_lvl_in_tree(struct ListNode_ *ls){

	struct ListNode_ *newLs = (struct ListNode_ *)malloc(sizeof(struct ListNode_));
	init_list(newLs,0,NULL,NULL);

	struct Node *conductor = ls->head;
	while(conductor != NULL){
	//	 printf("1 I'm ok \n");
		struct TreeNode *left = conductor->val->left;
		struct TreeNode *right = conductor->val->right;

		if(left != NULL){
			push_element_to_list(left, newLs);
		}
		if(right != NULL){
			push_element_to_list(right, newLs);
		}
		conductor = conductor -> next;
	}
	return newLs;

}
bool isSymmetric(struct TreeNode* root) {
	
    if(root == NULL){
    	return true;
    }
    if(root -> left == NULL && root->right == NULL){
        return true;
    }
    if(root -> left == NULL && root -> right != NULL || root -> left != NULL && root -> right == NULL){
    	return false;
    }
    if(root -> left -> val != root -> right ->val){
    	return false;
    }

    struct ListNode_ *lvlList = (struct ListNode_ *) malloc(sizeof(struct ListNode_));
    init_list(lvlList,0,NULL,NULL);

    push_element_to_list(root -> left,lvlList);
    push_element_to_list(root -> right,lvlList);
    
    while((lvlList->count) > 0){
    //	printf("lvl count -> %d \n",lvlList->count);
    	bool result = is_list_symmetric(lvlList);
       // printf("0 start I'm ok \n");
    	if(result == false){
    		return false;
    	}else{
    		struct ListNode_ *tmp = lvlList;
    		lvlList = generate_list_lvl_from_given_lvl_in_tree(lvlList);
    		free_list(tmp);
    	}
    //	printf("0 end I'm ok \n");
    }
	return true;

}


//recursive solution
/*
bool compare_left_right(struct TreeNode* leftNode, struct TreeNode* rightNode){

	if(leftNode == NULL && rightNode != NULL || rightNode == NULL && leftNode != NULL){
		return false;
	}
	if(leftNode == NULL && rightNode == NULL){
		return true;
	}

	bool result = true;

	result &= leftNode -> val == rightNode -> val;
	result &= compare_left_right(leftNode->left, rightNode->right);
	result &= compare_left_right(leftNode->right, rightNode->left);
	return result;

}

bool isSymmetric(struct TreeNode* root) {
    
    if(root == NULL){
    	return true;
    }
    
	return compare_left_right(root->left,root->right);

}
*/

/*
[1,2,2,null,3,3]
[1,2,2,3,null,null,3]
[1]
[1,2,2,null,3,3]
[1,2,2,3,4,4,3]
[1,2,2,null,3,null,3]
[null]
[1,2,null,3,3]
[1,null,2,3,3]
*/
