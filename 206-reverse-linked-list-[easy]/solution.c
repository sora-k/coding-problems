//12/10/16 (iterative solution) 2:03PM - 2:21PM
//         (recursive solution) 2:21PM - 2:36PM
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 1->2->3->4->NULL
// 
//iterative solution
/*
struct ListNode* reverseList(struct ListNode* head) {
    
    struct ListNode *prev = NULL;
    struct ListNode *conductor = head;

    while(conductor != NULL){
        struct ListNode *tmp = conductor;
        conductor = conductor->next;

        tmp->next = prev;
        prev = tmp;
    }

    return prev;
}
*/
// 1->2->3->4->NULL
//recursive solution
struct ListNode* reverse_recursive(struct ListNode* prev, struct ListNode* cur){
    
    struct ListNode *next = NULL;
    
    if(cur == NULL){
        return prev;
    }else{
        next = cur->next;
        cur->next = prev;
    }
    return reverse_recursive(cur,next);

}

struct ListNode* reverseList(struct ListNode* head) {
    
    struct ListNode *result = reverse_recursive(NULL,head);
    
    return result;

}
