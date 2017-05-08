#include <stdio.h>
#include <stdlib.h>
/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/*
 * Definition for singly-linked list.
 */ 
struct ListNode {
      int val;
      struct ListNode *next;
 };
struct ListNode* initNode(int val, struct ListNode* next){
	
	struct ListNode* node;
	
	node = (struct ListNode *) malloc(sizeof(struct ListNode));
	node -> val = val;
	node -> next = next;
	return node;
}
struct ListNode* createLinkedListFromArr(int arr[], int length, int offset){
	
	if(arr == NULL) return NULL;

	int i = offset;
	struct ListNode* head = initNode(arr[i],NULL);
	struct ListNode* conductor = head;

	for(i = i + 1; i < length; i++){
		conductor -> next = initNode(arr[i],NULL);
		conductor = conductor->next; 
	}
	return head;
		
}
void printLinkedList(struct ListNode *head){
	
	struct ListNode * conductor = head;

	while(conductor != NULL){
	    printf("%d -> ", conductor->val);
	    conductor = conductor -> next;
	}
	printf("NULL\n");

}
int linkedListToIntReverse(struct ListNode * head){

	int result = 0;
	int ten = 1;

	while( head != NULL){
	    result += ((head -> val) * ten);
	    ten *= 10;
	    head = head -> next;
	}
	return result;

}
struct ListNode* intToLinkedListReverse(int input){

	if(input == 0) {
	    return NULL;
	}

	struct ListNode * head = initNode(input % 10,NULL);
	struct ListNode *conductor = head;
	input /= 10;

	while(input != 0){
	    conductor -> next = initNode(input % 10,NULL);
	    conductor = conductor -> next;
	    input /= 10;
	}
	return head;
}
int power(int num, int pwr){
    
    int result = num;
    pwr--;
    
    while(pwr > 0){
        result *= num;
        pwr--;
    }
    return result;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	
	int carry = 0;
	int added = 0;

	struct ListNode * conductor1 = l1;
	struct ListNode * conductor2 = l2;
	struct ListNode * result = NULL;
	struct ListNode * resultHead = NULL;

	while(conductor1 != NULL){
	    
	    int val2 = (conductor2 == NULL) ? 0 : conductor2 -> val;
	    
	    added = conductor1 -> val + val2;
	    added += carry;
	    carry = added / 10;
	    added = (added > 9) ? added%10 : added;
	    
	    if(result == NULL){
		result = initNode(added,NULL);
		resultHead = result;
	    }
	    else{
		result -> next = initNode(added,NULL);
		result = result -> next;
	    }
	
	    conductor1 = conductor1 -> next;
	    conductor2 = (conductor2 == NULL) ? conductor2 : conductor2 -> next;
	}
	while(conductor2 != NULL){
	    added = conductor2 -> val + carry;
	    carry = added/10;
	    added = (added > 9) ? added%10 : added;
	    
	    if(result == NULL){
                result = initNode(added,NULL);
                resultHead = result;
            }
            else{
                result -> next = initNode(added,NULL);
                result = result -> next;
            }

	    conductor2 = conductor2 -> next;
	}
	if( carry != 0){
	    result -> next = initNode(carry, NULL);
	}
	return resultHead;
}
/*
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	
	int l1Int = linkedListToIntReverse((struct ListNode *)l1);
	int l2Int = linkedListToIntReverse((struct ListNode *)l2);
   	int result = l1Int + l2Int;
	printf("l1Int %d \n", l1Int);
   	printf("l2Int %d \n", l2Int);
	printf("result : %d \n", result);
    	if(result == l1Int){    // zero list case
            return l1;
    	}	
    	if(result == l2Int){
            return l2;
    	}
	return intToLinkedListReverse(result);
}
*/
void main(){

	#if 0
	int arr[] = {1,9,9,9,9,9,9,9,9,9};
	int arr2[] = {9};	
	#endif
	int arr2[] = {0};

	struct ListNode * head = createLinkedListFromArr(NULL,0,0);
	struct ListNode * head2 = createLinkedListFromArr(arr2,1,0);
	printLinkedList(head);
	printLinkedList(head2);
	struct ListNode * result = addTwoNumbers(head, head2);
	printLinkedList(result);	

	#if 0
	printLinkedList(head);
	printLinkedList(head2);
	printf("%d \n", linkedListToInt(head));
	printf("%d \n", linkedListToInt(head2));

	int x = 12345;
	struct ListNode * head3;
	head3 = intToLinkedListReverse(x);
	printLinkedList(head3);
	#endif
}

