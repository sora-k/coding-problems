// 11/29/16 (paper solution) 5:50 - 5:59PM
// 12/1/16 (coding) 7:03PM - 7:36PM

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// Floyd cycle detection solution
// None destructive!!
bool hasCycle(struct ListNode *head) {
    
    bool result = false;

    struct ListNode *fastPtr = head;
    struct ListNode *slowPtr = head;

    while(fastPtr != NULL){
        slowPtr = slowPtr -> next;
        fastPtr = fastPtr -> next;

        if(fastPtr == NULL){
            break;
        }else{
            fastPtr = fastPtr -> next;
        }
        if(slowPtr == fastPtr){
            result = true;
            break;
        }
    }
    return result;

}

//NOTE: watch where your pointing! if the memory is freed, you can't point to that memory anymore!!
/*
bool hasCycle(struct ListNode *head) {
    
    if(head == NULL){
        return false;
    }
    
    struct ListNode *flag = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *conductor = head;

    while(conductor != NULL){
    	struct ListNode *tmp = conductor;
    	conductor = conductor->next;
    	tmp->next = flag;

    	if(conductor == flag){
    	    head->next = NULL;
    	    free(flag);
    		return true;
    	}
    }
    head->next = NULL;
    free(flag);
    return false;
}
*/