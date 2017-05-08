#include <stdio.h>
// started 11/15/16 8:00 am, include 8hrs of work, include 3hr of play and travel
// end 6:57 pm
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    struct ListNode *prevNode;
    struct ListNode *currentNode;
    struct ListNode *targetNode;

    int space = 0;

    currentNode = head;
    targetNode = head;
    prevNode = head;

    while(currentNode != NULL){	//find target node

    	if(space == n){
    		prevNode = targetNode;
    		targetNode = targetNode -> next;
    	}else{
    		space++;
    	}
    	currentNode = currentNode -> next;
    }
    if(prevNode == targetNode){// case in which n is invalid (e.g. greater than lenght of list or negative) -> just remove the head
        head = targetNode -> next;
    }else{
        prevNode -> next = targetNode -> next;	//remove node
    }
    free(targetNode);

    return head;
}