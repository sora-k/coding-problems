#include <stdio.h>
// started 11/16/16 8:30 - 9:30 am -> work, workout -> start again 8:17pm , finish 8:39pm
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    
    struct ListNode *currNode = head;
    struct ListNode *prevNode = NULL;
    head = NULL;

    while(currNode != NULL){

    	struct ListNode *node1 = currNode;
    	struct ListNode *node2 = currNode -> next;
    	if(head == NULL){
    		head = (node2 != NULL) ? node2 : node1;
    	}
    	if(node2 != NULL){ //swap
    		currNode = node2 -> next;
    		node1 -> next = currNode;
    		node2 -> next = node1;
    		if(prevNode != NULL){
    			prevNode -> next = node2;
    		}
    		prevNode = node1;
    	}else{
    		currNode = NULL;
    	}

    }
    return head;

}