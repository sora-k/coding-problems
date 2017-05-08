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
void printList(struct _ListNode *list, int printChar){
	
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
		// printList(currList, 0);
		// TODO: don't forget to free mem from malloc
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
			forwardConductor = forwardConductor -> next;
		}
		backwardConductor = backwardConductor -> prev;
		forwardConductor = repeatedCharListInd -> head;
	}
	newMax = (newMax > currentMaxLen) ? newMax : currentMaxLen ;
	return newMax;

}
void print_char_ptr(char *c){
	
	while(*c != '\0'){
		printf("%c ",*c);
		c++;
	}
	printf("\n");
}
void print_char(char s[], int startInd, int endInd){

	int i;
	for(i = startInd; i < endInd + 1 ; i++){
		printf("%c ", s[i]);
	}
}
void free_mem_list(struct _ListNode list){

}
void free_processed_mem(struct _ListNode **lists,struct _ListNode repeatedCharList){

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
	
	// struct Node *conductor = repeatedCharList -> head;
	// while(conductor != NULL){
	// 	printf("========%c======", conductor -> data);
	// 	printList(proccessed[conductor->data], 0);
	// 	conductor = conductor -> next;
	// 	printf("\n");
	// }

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

void main(){

	char test0[] = {'1','2','3','4','8','9','5','1','0','1','5','1','0','8','7','1','1','\0'};
	char test1[] = {'0','1','5','1','0','\0'};
	char test2[] = {'0','1','1','0','\0'};
	char test3[] = {'a','a','a','\0'};
	char test4[] = {'a','a','\0'};
	char test5[] = {'a','b','\0'};
	char test6[] = {'a','\0'};
	char test7[] = {'\0'};
	// expected answer -> "ranynar"
	char test8[] = {'c', 'i', 'v', 'i', 'l', 'w', 'a', 'r', 't', 'e', 's', 't', 'i', 'n', 'g', 'w', 'h', 'e', 't', 'h', 'e', 'r', 't', 'h', 'a', 't', 'n', 'a', 'p', 't', 'i', 'o', 'n', 'o', 'r', 'a', 'n', 'y', 'n', 'a', 'r', 't', 'i', 'o', 'n', 's', 'o', 'c', 'o', 'n', 'c', 'e', 'i', 'v', 'e', 'd', 'a', 'n', 'd', 's', 'o', 'd', 'e', 'd', 'i', 'c', 'a', 't', 'e', 'd', 'c', 'a', 'n', 'l', 'o', 'n', 'g', 'e', 'n', 'd', 'u', 'r', 'e', 'W', 'e', 'a', 'r', 'e', 'q', 'm', 'e', 't', 'o', 'n', 'a', 'g', 'r', 'e', 'a', 't', 'b', 'a', 't', 't', 'l', 'e', 'f', 'i', 'e', 'm', 'l', 'd', 'o', 'f', 't', 'z', 'h', 'a', 't', 'w', 'a', 'r', 'W', 'e', 'h', 'a', 'v', 'e', 'c', 'o', 'm', 'e', 't', 'o', 'd', 'e', 'd', 'i', 'c', 'p', 'a', 't', 'e', 'a', 'p', 'o', 'r', 't', 'i', 'o', 'n', 'o', 'f', 't', 'h', 'a', 't', 'f', 'i', 'e', 'l', 'd', 'a', 's', 'a', 'f', 'i', 'n', 'a', 'l', 'r', 'e', 's', 't', 'i', 'n', 'g', 'p', 'l', 'a', 'c', 'e', 'f', 'o', 'r', 't', 'h', 'o', 's', 'e', 'w', 'h', 'o', 'h', 'e', 'r', 'e', 'g', 'a', 'v', 'e', 't', 'h', 'e', 'i', 'r', 'l', 'i', 'v', 'e', 's', 't', 'h', 'a', 't', 't', 'h', 'a', 't', 'n', 'a', 't', 'i', 'o', 'n', 'm', 'i', 'g', 'h', 't', 'l', 'i', 'v', 'e', 'I', 't', 'i', 's', 'a', 'l', 't', 'o', 'g', 'e', 't', 'h', 'e', 'r', 'f', 'a', 'n', 'g', 'a', 'n', 'd', 'p', 'r', 'o', 'p', 'e', 'r', 't', 'h', 'a', 't', 'w', 'e', 's', 'h', 'o', 'u', 'l', 'd', 'd', 'o', 't', 'h', 'i', 's', 'B', 'u', 't', 'i', 'n', 'a', 'l', 'a', 'r', 'g', 'e', 'r', 's', 'e', 'n', 's', 'e', 'w', 'e', 'c', 'a', 'n', 'n', 'o', 't', 'd', 'e', 'd', 'i', 'c', 'a', 't', 'e', 'w', 'e', 'c', 'a', 'n', 'n', 'o', 't', 'c', 'o', 'n', 's', 'e', 'c', 'r', 'a', 't', 'e', 'w', 'e', 'c', 'a', 'n', 'n', 'o', 't', 'h', 'a', 'l', 'l', 'o', 'w', 't', 'h', 'i', 's', 'g', 'r', 'o', 'u', 'n', 'd', 'T', 'h', 'e', 'b', 'r', 'a', 'v', 'e', 'l', 'm', 'e', 'n', 'l', 'i', 'v', 'i', 'n', 'g', 'a', 'n', 'd', 'd', 'e', 'a', 'd', 'w', 'h', 'o', 's', 't', 'r', 'u', 'g', 'g', 'l', 'e', 'd', 'h', 'e', 'r', 'e', 'h', 'a', 'v', 'e', 'c', 'o', 'n', 's', 'e', 'c', 'r', 'a', 't', 'e', 'd', 'i', 't', 'f', 'a', 'r', 'a', 'b', 'o', 'v', 'e', 'o', 'u', 'r', 'p', 'o', 'o', 'r', 'p', 'o', 'n', 'w', 'e', 'r', 't', 'o', 'a', 'd', 'd', 'o', 'r', 'd', 'e', 't', 'r', 'a', 'c', 't', 'T', 'g', 'h', 'e', 'w', 'o', 'r', 'l', 'd', 'a', 'd', 's', 'w', 'f', 'i', 'l', 'l', 'l', 'i', 't', 't', 'l', 'e', 'n', 'o', 't', 'l', 'e', 'n', 'o', 'r', 'l', 'o', 'n', 'g', 'r', 'e', 'm', 'e', 'm', 'b', 'e', 'r', 'w', 'h', 'a', 't', 'w', 'e', 's', 'a', 'y', 'h', 'e', 'r', 'e', 'b', 'u', 't', 'i', 't', 'c', 'a', 'n', 'n', 'e', 'v', 'e', 'r', 'f', 'o', 'r', 'g', 'e', 't', 'w', 'h', 'a', 't', 't', 'h', 'e', 'y', 'd', 'i', 'd', 'h', 'e', 'r', 'e', 'I', 't', 'i', 's', 'f', 'o', 'r', 'u', 's', 't', 'h', 'e', 'l', 'i', 'v', 'i', 'n', 'g', 'r', 'a', 't', 'h', 'e', 'r', 't', 'o', 'b', 'e', 'd', 'e', 'd', 'i', 'c', 'a', 't', 'e', 'd', 'h', 'e', 'r', 'e', 't', 'o', 't', 'h', 'e', 'u', 'l', 'n', 'f', 'i', 'n', 'i', 's', 'h', 'e', 'd', 'w', 'o', 'r', 'k', 'w', 'h', 'i', 'c', 'h', 't', 'h', 'e', 'y', 'w', 'h', 'o', 'f', 'o', 'u', 'g', 'h', 't', 'h', 'e', 'r', 'e', 'h', 'a', 'v', 'e', 't', 'h', 'u', 's', 'f', 'a', 'r', 's', 'o', 'n', 'o', 'b', 'l', 'y', 'a', 'd', 'v', 'a', 'n', 'c', 'e', 'd', 'I', 't', 'i', 's', 'r', 'a', 't', 'h', 'e', 'r', 'f', 'o', 'r', 'u', 's', 't', 'o', 'b', 'e', 'h', 'e', 'r', 'e', 'd', 'e', 'd', 'i', 'c', 'a', 't', 'e', 'd', 't', 'o', 't', 'h', 'e', 'g', 'r', 'e', 'a', 't', 't', 'd', 'a', 'f', 's', 'k', 'r', 'e', 'm', 'a', 'i', 'n', 'i', 'n', 'g', 'b', 'e', 'f', 'o', 'r', 'e', 'u', 's', 't', 'h', 'a', 't', 'f', 'r', 'o', 'm', 't', 'h', 'e', 's', 'e', 'h', 'o', 'n', 'o', 'r', 'e', 'd', 'd', 'e', 'a', 'd', 'w', 'e', 't', 'a', 'k', 'e', 'i', 'n', 'c', 'r', 'e', 'a', 's', 'e', 'd', 'd', 'e', 'v', 'o', 't', 'i', 'o', 'n', 't', 'o', 't', 'h', 'a', 't', 'c', 'a', 'u', 's', 'e', 'f', 'o', 'r', 'w', 'h', 'i', 'c', 'h', 't', 'h', 'e', 'y', 'g', 'a', 'v', 'e', 't', 'h', 'e', 'l', 'a', 's', 't', 'p', 'f', 'u', 'l', 'l', 'm', 'e', 'a', 's', 'u', 'r', 'e', 'o', 'f', 'd', 'e', 'v', 'o', 't', 'i', 'o', 'n', 't', 'h', 'a', 't', 'w', 'e', 'h', 'e', 'r', 'e', 'h', 'i', 'g', 'h', 'l', 'y', 'r', 'e', 's', 'o', 'l', 'v', 'e', 't', 'h', 'a', 't', 't', 'h', 'e', 's', 'e', 'd', 'e', 'a', 'd', 's', 'h', 'a', 'l', 'l', 'n', 'o', 't', 'h', 'a', 'v', 'e', 'd', 'i', 'e', 'd', 'i', 'n', 'v', 'a', 'i', 'n', 't', 'h', 'a', 't', 't', 'h', 'i', 's', 'n', 'a', 't', 'i', 'o', 'n', 'u', 'n', 's', 'd', 'e', 'r', 'G', 'o', 'd', 's', 'h', 'a', 'l', 'l', 'h', 'a', 'v', 'e', 'a', 'n', 'e', 'w', 'b', 'i', 'r', 't', 'h', 'o', 'f', 'f', 'r', 'e', 'e', 'd', 'o', 'm', 'a', 'n', 'd', 't', 'h', 'a', 't', 'g', 'o', 'v', 'e', 'r', 'n', 'm', 'e', 'n', 't', 'o', 'f', 't', 'h', 'e', 'p', 'e', 'o', 'p', 'l', 'e', 'b', 'y', 't', 'h', 'e', 'p', 'e', 'o', 'p', 'l', 'e', 'f', 'o', 'r', 't', 'h', 'e', 'p', 'e', 'o', 'p', 'l', 'e', 's', 'h', 'a', 'l', 'l', 'n', 'o', 't', 'p', 'e', 'r', 'i', 's', 'h', 'f', 'r', 'o', 'm', 't', 'h', 'e', 'e', 'a', 'r', 't', 'h','\0'};
	char *result;
	// result = longestPalindrome(test0);
	// print_char_ptr(result);
	// printf("*****************************\n");
	// result = longestPalindrome(test1);
	// print_char_ptr(result);
	// printf("*****************************\n" );
	// result = longestPalindrome(test2);
	// print_char_ptr(result);
	// printf("*****************************\n");
	// result = longestPalindrome(test3);
	// print_char_ptr(result);
	// printf("*****************************\n");
	// result = longestPalindrome(test4);
	// print_char_ptr(result);
	// printf("*****************************\n");
	// result = longestPalindrome(test5);
	// print_char_ptr(result);
	// printf("*****************************\n");
	// result = longestPalindrome(test6);
	// print_char_ptr(result);
	// printf("*****************************\n");
	// result = longestPalindrome(test7);
	// print_char_ptr(result);

	printf("*****************************\n");
	result = longestPalindrome(test8);
	print_char_ptr(result);


	// printf("test1 result: %d\n", is_palin(test1,0, sizeof(test1)/sizeof(test1[0]) - 1));
	// printf("test2 result: %d\n", is_palin(test2,0, sizeof(test2)/sizeof(test2[0]) - 1));
	// printf("test3 result: %d\n", is_palin(test3,0, sizeof(test3)/sizeof(test3[0]) - 1));
	// printf("test4 result: %d\n", is_palin(test4,0, sizeof(test4)/sizeof(test4[0]) - 1));
	// printf("test5 result: %d\n", is_palin(test5,0, sizeof(test5)/sizeof(test5[0]) - 1));

}