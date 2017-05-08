// 11/29/16 (paper solution) 7:55PM - 8:07PM
// 12/10/16 (coding) 1:00AM - 1:34AM

//TODO: improve efficiency!!

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int count_node(struct ListNode *head){

    struct ListNode *conductor = head;
    int count = 0;

    while(conductor != NULL){
        conductor = conductor->next;
        count++;
    }

    return count;
}
struct ListNode *get_node_at(struct ListNode *head, int index){

    struct ListNode *result = NULL;
    struct ListNode *conductor = head;
    int currInd = 0;

    while(conductor != NULL){
        if(currInd == index ){
            result = conductor;
            break;
        }

        conductor = conductor->next;
        currInd++;
    }

    return result;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    struct ListNode *result = NULL;

    int cntA = count_node(headA);
    int cntB = count_node(headB);

    struct ListNode *conductorA = (cntA > cntB) ? get_node_at(headA,cntA - cntB) : headA;
    struct ListNode *conductorB = (cntB > cntA) ? get_node_at(headB,cntB - cntA) : headB;

    while(conductorA != NULL && conductorB != NULL){
        if(conductorA == conductorB){
            result = conductorA;
            break;
        }        
        
        conductorA = conductorA->next;
        conductorB = conductorB->next;
    }

    return result;
}