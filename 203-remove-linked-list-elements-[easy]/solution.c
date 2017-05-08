//12/15/16 10:30 - 11:02PM
//		try again but faster, try with a piece of paper

// optimized solution
struct ListNode* removeElements(struct ListNode* head, int val) {
    
    struct ListNode **pp = &head;
    struct ListNode *p;
    
    while(*pp != NULL){
        p = *pp;
        if(p -> val == val){
            *pp = p -> next;
            free(p);
        }else{
            pp = &(p->next);
        }
    }
    return head;
}


//TODO: optimize the code!, not beating a lot of people

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
struct ListNode* removeElements(struct ListNode* head, int val) {
    
    struct ListNode *prev = NULL;
    struct ListNode *conductor = head;

    while(conductor != NULL){

    	if(conductor->val == val){
    		struct ListNode *nextNode = conductor -> next;
    		
    		if(conductor == head){
    			head = nextNode;
    		}else{
    			prev->next = nextNode;
    		}
    		free(conductor);
    		conductor = nextNode;
    	}else{
    		prev = conductor;
    		conductor = conductor -> next;
		}
    }
    return head;
}
*/