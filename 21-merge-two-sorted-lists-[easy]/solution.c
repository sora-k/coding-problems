#include <stdio.h>
#include <stdlib.h>

// started  11/15/16 11:00 pm sleep 12:00 - > 7:00 am,Finish  11/16/16 8:28 a.m.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// observation:
// 1. Last node always point to NULL

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
	struct ListNode *result = NULL;
	struct ListNode *conductor1 = l1;
	struct ListNode *conductor2 = l2;
	struct ListNode *conResult;
	struct ListNode *greater;
	struct ListNode *lesser;

	while(conductor1 != NULL){
		
		if(conductor2 != NULL){
			int val1 = conductor1 -> val;
			int val2 = conductor2 -> val;
			greater = (val1 > val2) ? conductor1 : conductor2;
			lesser = (val1 > val2) ? conductor2 : conductor1;

			if(result == NULL){
				result = lesser;
				conResult = result;
			}else{
				conResult -> next = lesser;
				conResult = lesser;
			}
			conductor1 = (conductor1 == lesser) ? conductor1 -> next : conductor1;
			conductor2 = (conductor2 == lesser) ? conductor2 -> next : conductor2;
		}else{
			lesser = conductor1;

			if(result == NULL){
				result = lesser;
				conResult = result;
			}else{
				conResult -> next = lesser;
				conResult = lesser;
			}
			conductor1 = conductor1 -> next;
		}
	}
	while(conductor2 != NULL){
		
		lesser = conductor2;
		
		if(result == NULL){
			result = lesser;
			conResult = result;
		}else{
			conResult -> next = lesser;
			conResult = lesser;
		}
		conductor2 = conductor2 -> next;
	}

	return result;
}



