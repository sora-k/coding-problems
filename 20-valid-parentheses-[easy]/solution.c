#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//started 11/15/16 7:12 pm - 8:48 pm
//TODO: improve readability of this code
//Note: alternate implementation of stack is to use linked list.

bool isValid(char* s) {
    
    bool result = true;

    char patternArr[127];           // initialized pattern arr, map open to close parentheses
    memset(patternArr,'\0',sizeof(patternArr));
    
    patternArr['('] = ')'; patternArr[')'] = 'c'; // () //note: c stands for closing parentheses char.
    patternArr['['] = ']'; patternArr[']'] = 'c'; // []
    patternArr['{'] = '}'; patternArr['}'] = 'c'; // {}

    char *currChar = s;                 //initialize stack array
    int count = 0;
    while(*currChar != NULL){
        count++;
        currChar++;
    }
    int currInd = -1;
    char closeParenStackArr[count];
    
    currChar = s;                           //check string
    while(*currChar != NULL){
        char closePChar = patternArr[*currChar];

        if(closePChar != '\0'){
            if(closePChar != 'c'){
                //printf("store expect %c \n",closePChar);
                currInd++;
                closeParenStackArr[currInd] = closePChar;
            }else{
                if(currInd != -1){
                    char expectCloseP = closeParenStackArr[currInd];
                    
                    if(*currChar != expectCloseP){
                       //printf("unexpected close: %c, expect %c \n",*currChar ,expectCloseP);
                        result = false;
                        break;
                    }else{
                        currInd--;
                    }
                }else{
                    result = false;
                    break;
                }
            }
        }
        else{   
            result = false;
            break;
        }
        currChar++;
    }
    if(currInd != -1){
        result = false;
    }
    return result;
}

/*
""
"}}"
"{({})[][s][{}]}"
"}{({})[][][{}]}"
"{({})[][][{}]}"
*/