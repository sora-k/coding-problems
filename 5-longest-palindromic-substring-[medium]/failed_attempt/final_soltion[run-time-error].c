#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT 1000
#define ASCII_SIZE 255

struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
};
struct _ListNode
{
	char data;
	struct Node *head;
	struct Node *last;
	int listLen;
};
struct Node* init_node(int data, struct Node* next, struct Node* prev){

        struct Node* node;

        node = (struct Node *) malloc(sizeof(struct Node));
        node -> data = data;
        node -> next = next;
        node -> prev = prev;

        return node;
}
int is_palin(char str[], int startInd, int endInd){
	
	int result = 1;

	while(startInd < endInd){
		if(str[startInd] != str[endInd]){
			result = 0;
			break;
		}
		startInd++;
		endInd--;
	}
	return result;
}
int store_repeated_chars_ind_and_get_arr_size(char *s, struct _ListNode **proccessed, struct _ListNode **repeatedCharLst){

	int count = 0;
	char *ptr = s;
	struct Node *newNode;
	struct Node *repeatedCharNode;
	struct _ListNode *currList;
	struct _ListNode *listNode;
	char currChar;
	
	char seen[ASCII_SIZE];
	memset(seen,'\0', sizeof(seen));
	struct _ListNode *repeatedCharList =  (struct _ListNode *) malloc(sizeof(struct _ListNode));
	repeatedCharList -> head = NULL;
	repeatedCharList -> listLen = 0;
	repeatedCharList -> data = 'X';

	while(*ptr){
		
		newNode = init_node(count, NULL,NULL);
		currChar = *ptr;
		currList = proccessed[currChar];

		if(currList == NULL){				//init list that stores ind of a char
			listNode = (struct _ListNode *) malloc(sizeof(struct _ListNode));	//TODO - put node operations into a function
			listNode -> data = currChar;
			listNode -> head = newNode;
			listNode -> last = newNode;
			listNode -> listLen = 1;

			proccessed[currChar] = listNode; 
			currList = listNode; 
		}
		else{
			newNode -> prev = currList -> last;
			currList -> last -> next = newNode;
			currList -> last = newNode;
			currList -> listLen += 1;

			if(currList -> listLen >= 2 && seen[currChar] == '\0'){	// save repeated chars into a list

				seen[currChar] = 'T';
				repeatedCharNode = init_node(currChar,NULL,NULL);
				repeatedCharList -> head = (repeatedCharList -> head == NULL) ? repeatedCharNode : repeatedCharList -> head;

				if(repeatedCharList -> last != NULL){
					repeatedCharNode -> prev = repeatedCharList -> last;
					repeatedCharList -> last -> next = repeatedCharNode;
				}
				repeatedCharList -> last = repeatedCharNode;
				repeatedCharList -> listLen += 1;
			}
		}
		ptr++;
		count++;
	}
	*repeatedCharLst = repeatedCharList;
	return count;
}
int find_max_palindrome_ind(int currentMaxLen, char* s,struct _ListNode *repeatedCharListInd, int *startInd, int *endInd){
	
	int newMax = -1;
	int currLen; int currStartInd; int currEndInd;
	struct Node *forwardConductor = repeatedCharListInd -> head;
	struct Node *backwardConductor = repeatedCharListInd -> last;

	while(backwardConductor){
		while(forwardConductor != backwardConductor){
			currStartInd = forwardConductor -> data;
			currEndInd = backwardConductor -> data;
			currLen = (currEndInd - currStartInd) + 1;
			
			if(currLen > newMax){
				int isPalin = is_palin(s,currStartInd,currEndInd);
				
				if(isPalin == 1){
					*startInd = currStartInd;
					*endInd = currEndInd;
					newMax = currLen;
				}
			}
			else{
				break;
			}
			forwardConductor = forwardConductor -> next;
		}
		backwardConductor = backwardConductor -> prev;
		forwardConductor = repeatedCharListInd -> head;
	}
	newMax = (newMax > currentMaxLen) ? newMax : currentMaxLen ;
	return newMax;

}
char* longestPalindrome(char *s){
	
	char *result = s; 
	int resultStartInd;
	int resultEndInd;
	int longestLen = 1;

	struct _ListNode *proccessed[ASCII_SIZE];
	struct _ListNode *repeatedCharList = NULL;
	memset(proccessed,'\0', sizeof(proccessed));
	int count = store_repeated_chars_ind_and_get_arr_size(s,proccessed,&repeatedCharList);
	
	struct Node *conductor = repeatedCharList -> head;
	if(conductor){
		while(conductor){
			char currChar = conductor->data;
			struct _ListNode *currCharIndList = proccessed[currChar];
			longestLen = find_max_palindrome_ind(longestLen,s,currCharIndList, &resultStartInd, &resultEndInd);
			conductor = conductor -> next;
		}
	}else{
		resultStartInd = -1;
		resultEndInd = -1;
	}
	if(resultStartInd != -1 && resultEndInd != -1){
		result = s + resultStartInd;
		if(*(s + resultEndInd) != '\0'){
			*(s + resultEndInd + 1) = '\0';
		}
	}
	return result;
}
