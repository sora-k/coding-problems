// 11/19/16 4:46pm - 10:28pm
#include <stdio.h>

struct Node{
	char val;
	struct Node *next;
};
char * construct_str_from_nodes(struct Node *s){

	char *result = NULL;
	struct Node *head = s;
	int count = 0;

	while(head != NULL){
		count++;
		head = head -> next;
	}
	result = (char *)malloc(sizeof(char)*(count + 1));

	int i;
	for(i = 0; i < count; i++){
		char c = s -> val;
		result[i] = c;
		s = s -> next;
	}
	free_node_list(s);
	result[count] = '\0';
	
	return result;
}
struct Node *init_node(struct Node *next, char val){

	struct Node *result = (struct Node *)malloc(sizeof(struct Node));
	result -> next = next;
	result -> val = val;

	return result;
}
void free_node_list(struct Node *head){

	while(head != NULL){
		struct Node *tmp = head;
		head = head -> next;
		free(tmp);
	}

}
char* countAndSay(int n) {
    
    char *result;
	struct Node *resultList = (struct Node *)malloc(sizeof(struct Node));
	resultList -> val = '1';
	resultList -> next = NULL;

	if(n == 1){
		result = construct_str_from_nodes(resultList);
	    return result;
	}

    struct Node *newLast;
	struct Node *newList = NULL;
	struct Node *ptr = resultList;
	while(n > 1){
	    
		while(ptr != NULL){
			char currDigit = ptr -> val;
			int count = 0;
			
			while((ptr -> val) == currDigit){
				count++;
				ptr = ptr -> next;
				
				if(ptr == NULL){
					break;
				}
			}
			struct Node *numNode = init_node(NULL, currDigit);
			struct Node *cntNode = init_node(numNode, count + '0');

			if(newList == NULL){
				newList = cntNode;
				newLast = numNode;
			}else{
				newLast -> next = cntNode;
				newLast = numNode;
			}
		}
		free_node_list(resultList);
		resultList = newList;
		ptr = newList;
		newList = NULL;
		n--;
	}
	result = construct_str_from_nodes(resultList);
	return result;
}

/*
4
3
2
1
*/