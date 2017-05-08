// To Run, paste this in LeetCode
struct ListNode* initNode(int val, struct ListNode* next){

        struct ListNode* node;

        node = (struct ListNode *) malloc(sizeof(struct ListNode));
        node -> val = val;
        node -> next = next;
        return node;
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

