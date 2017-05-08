#include <stdio.h>
// 11/21/16 started 9:00 pm - 11:41pm
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    
    struct ListNode* conductor = head;
  	struct ListNode* nextNode;
  	
    while(conductor != NULL){
    	nextNode = conductor -> next;

    	if(nextNode != NULL){
    		if(conductor -> val == nextNode -> val){
    			if(conductor == head){
    				head -> next = nextNode -> next;
    			}else{
    				conductor -> next = nextNode -> next;
    			}
    			free(nextNode);
    		}else{
    			conductor = conductor -> next;
    		}
    	}else{
    		conductor = NULL;
    	}
    }
    return head;
}