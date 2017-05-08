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
struct ListNode
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
void printList(struct ListNode *list, int printChar){
	
	if(list != NULL){
		struct Node *conductor = list -> head;
		printf("list char: (%d)%c, list len: %d == ", list -> data,list -> data, list -> listLen);
		//conductor = conductor -> next;
		
		while(conductor != NULL){
			if(printChar == 1){
				printf("%d(%c),", conductor -> data, conductor -> data);
			}else{
				printf("%d,", conductor -> data);
			}
			conductor = conductor -> next;
		}
		printf("\n");
	}
}
int store_repeated_chars_ind_and_get_arr_size(char *s, struct ListNode **proccessed, struct ListNode **repeatedCharLst){

	int count = 0;
	char *ptr = s;
	struct Node *newNode;
	struct Node *repeatedCharNode;
	struct ListNode *currList;
	struct ListNode *listNode;
	char currChar;
	
	char seen[ASCII_SIZE];
	memset(seen,'\0', sizeof(seen));
	struct ListNode *repeatedCharList =  (struct ListNode *) malloc(sizeof(struct ListNode));
	repeatedCharList -> head = NULL;
	repeatedCharList -> listLen = 0;
	repeatedCharList -> data = 'X';

	while(*ptr){
		
		newNode = init_node(count, NULL,NULL);
		currChar = *ptr;
		currList = proccessed[currChar];

		if(currList == NULL){				//init list that stores ind of a char
			listNode = (struct ListNode *) malloc(sizeof(struct ListNode));	//TODO - put node operations into a function
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
		// printList(currList, 0);
		// TODO: don't forget to free mem from malloc
		ptr++;
		count++;
	}
	*repeatedCharLst = repeatedCharList;
	return count;
}
int find_max_palindrome_ind(int currentMaxLen, struct ListNode *list, int *startInd, int *endInd){
	
	int newMax = -1;
	int currLen; int currStartInd; int currEndInd;
	struct Node *forwadConductor = list -> head;
	struct Node *backwardConductor = list -> last;

	while(forwadConductor){
		currStartInd = forwadConductor -> data;
		currEndInd = backwardConductor -> data;
		currLen = currEndInd - currStartInd + 1;

		if(currLen > currentMaxLen){

		}

		backwardConductor = list -> last;
		forwadConductor = forwadConductor -> next;
	}


	return newMax;

}
char* longestPalindrome(char *s){
	
	char *result = s; 
	int largest = 1;

	struct ListNode *proccessed[ASCII_SIZE];
	struct ListNode *repeatedCharList = NULL;
	memset(proccessed,'\0', sizeof(proccessed));
	int count = store_repeated_chars_ind_and_get_arr_size(s,proccessed,&repeatedCharList);
	
	struct Node *conductor = repeatedCharList -> head;
	while(conductor){
		char currChar = conductor->data;
		struct ListNode *currCharIndList = proccessed[currChar];


		conductor = conductor -> next;
	}
	// struct Node *conductor = repeatedCharList -> head;
	// while(conductor != NULL){
	// 	printf("========%c======", conductor -> data);
	// 	printList(proccessed[conductor->data], 0);
	// 	conductor = conductor -> next;
	// 	printf("\n");
	// }

	//printf("count: %d\n", count);

	char *resultStart;
	char *resultEnd;
	int startInd; int endInd;

	//memcpy(void *dst, const void *src + offset, size_t count)

}

void main(){

	char test0[] = {'1','2','3','4','8','9','5','1','0','1','5','1','0','8','7','1','1','\0'};
	char test1[] = {'0','1','5','1','0','\0'};
	char test2[] = {'0','1','1','0','\0'};
	char test3[] = {'a','a','a','\0'};
	char test4[] = {'a','a','\0'};
	char test5[] = {'a','b','\0'};
	char test6[] = {'a','\0'};
	longestPalindrome(test0);
	printf("*****************************\n");
	longestPalindrome(test1);
	printf("*****************************\n" );
	longestPalindrome(test2);
	printf("*****************************\n");
	longestPalindrome(test3);
	printf("*****************************\n");
	longestPalindrome(test4);
	printf("*****************************\n");
	longestPalindrome(test5);
	printf("*****************************\n");
	longestPalindrome(test6);

	// printf("test1 result: %d\n", is_palin(test1,0, sizeof(test1)/sizeof(test1[0]) - 1));
	// printf("test2 result: %d\n", is_palin(test2,0, sizeof(test2)/sizeof(test2[0]) - 1));
	// printf("test3 result: %d\n", is_palin(test3,0, sizeof(test3)/sizeof(test3[0]) - 1));
	// printf("test4 result: %d\n", is_palin(test4,0, sizeof(test4)/sizeof(test4[0]) - 1));
	// printf("test5 result: %d\n", is_palin(test5,0, sizeof(test5)/sizeof(test5[0]) - 1));

}