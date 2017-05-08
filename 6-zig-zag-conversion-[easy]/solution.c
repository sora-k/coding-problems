// start at 10:30pm 11/7/16 -> finish 11/12/16 9:35:00 pm
#include <stdio.h>
#include <stdlib.h>


struct Node{
	struct Node *next;
	char data;
};
struct ListNode_{
	struct Node *head;
	struct Node *tail;
};
char* convert(char* s, int numRows) {

	char *result = s;
    
    if(numRows == 0 || numRows == 1 || numRows < 0 || *s == NULL){	// special cases
        return result;
    }
    
	struct ListNode_ *rowArr[numRows];
	memset(rowArr, NULL, sizeof(rowArr));

	int rowInd;
	int rowCnt = 0;
	struct Node *newNode; 
	for(rowInd = 0; rowInd < numRows; rowInd++){	//initialize row list
		if(*s == NULL){
			break;
		}
		struct ListNode_ *newList = (struct ListNode_ *) malloc(sizeof(struct ListNode_));
		newNode = (struct Node *) malloc(sizeof(struct Node));
		newNode -> data = *s;
		newNode -> next = NULL;
		newList -> head = newNode;
		newList -> tail = newNode;

		rowArr[rowInd] = newList;
		rowCnt++;
		//printf("%d row created %c \n",rowCnt,*s);
		s++;
	}
	

	rowInd -= 2;
	int goUpRows = 1;
	struct ListNode_ *curRow;
	while(*s != NULL){	//populate rows
		curRow = rowArr[rowInd];
		
		newNode = (struct Node *)malloc(sizeof(struct Node));
		newNode -> data = *s;
		newNode -> next = NULL;
		
		curRow -> tail -> next = newNode;
		curRow -> tail = newNode;
        //printf("at %d row, %c node created \n",rowInd,curRow -> tail->data);
		if(goUpRows == 1){ 
			if(rowInd - 1 < 0){
				goUpRows = 0;
				rowInd++;
			}else{
				rowInd--;
			}

		}else{
			if(rowInd + 1 == numRows){
				goUpRows = 1;
				rowInd--;
			}else{
				rowInd++;
			}
		}

		s++;
	}

	struct Node *done;
	s = result;
	int i;
	for(i = 0; i < rowCnt; i++){	//generate solution
		curRow = rowArr[i];
		struct Node *conductor;

		conductor = curRow -> head;
		while(conductor != NULL){
			*s = conductor -> data;
     		done = conductor;
			conductor = conductor -> next;
			free(done);
			s++;
		}
		free(curRow);
	}
    
	return result;
 
}