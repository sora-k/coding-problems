// started 2/4/17 4:25PM - 6:00PM
// started 2/5/17 7:23PM - 8:07PM  (took too long!!)
// TODO: redo this, make the code cleaner!

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/


class Solution {
public:
   bool isPalindrome(ListNode* head) {
      
      bool result  = false;
      int  nodeCnt = countNode(head);
      
      if(nodeCnt < 2){
                      return true;
      }
      
      int targetInd = (nodeCnt % 2 == 0) ? nodeCnt/2 - 1 : nodeCnt / 2;
      
      ListNode *ptrBeforeSecondHalf = head;
      for(int i = 0; i != targetInd; i++){
                      ptrBeforeSecondHalf = ptrBeforeSecondHalf->next;
      }
      
      ListNode* ptrSecondHalf = reverseList(ptrBeforeSecondHalf->next, nodeCnt/2, NULL); 
      result = compareLists(head, ptrSecondHalf, nodeCnt/2);
      reverseList(ptrSecondHalf, nodeCnt/2, NULL);

      return result;
      
   }
   bool compareLists(ListNode* l1, ListNode* l2, int count){

           bool result = true;

           if((l1 != NULL && l1 != NULL) == false){
                   return false;
           }

           for(int i = 0; i < count; ++i){
                   if(l1->val != l2->val){
                           result = false;
                           break;
                   }
                   l1 = l1->next;
                   l2 = l2->next;
           }
           return result;
   }
   void debugPrint(ListNode *head){

           while(head != NULL){
                   std::cout << head->val<<" ";
                   head = head->next;
           }
           std::cout<<std::endl;
           
   }
   int countNode(ListNode* head){

           int count = 0;

           while(head != NULL){
                   head = head -> next;
                   count++;
           }
           return count;
   }
   ListNode* reverseList(ListNode* head,int size, ListNode* iniPrev){
       
       ListNode* conductor = head;
       ListNode* prevNode  = iniPrev;
       ListNode* curNode;
       
       for(int i = 0; i < size; i++){
           if(conductor != NULL){
               curNode   = conductor;
               conductor = conductor->next;    
               curNode->next = prevNode;
               prevNode      = curNode;
           }
       }
       return curNode;
   }
};

/*
[]
[1]
[1,2]
[1,2,3]
[1,2,3,1,2]
[2,1,1,2]

*/