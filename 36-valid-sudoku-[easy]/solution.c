// started 11/19/16 1:00 pm - 4:07 pm

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUB_ROW_SIZE 3
#define SUB_COL_SIZE 3

bool check_sub_box(char** board, int curRow, int curCol, int rowSize, int colSize){

	bool result = true;
	char chkArr[10];
    memset(chkArr,'\0',sizeof(chkArr));
    char currE;

	int maxCol = curCol + colSize;
	int maxRow = curRow + rowSize;
	int i,j;
	for(i = curCol; i < maxCol; i++){
		for(j = curRow; j < maxRow; j++){
			currE = board[i][j];

			if(currE != '.'){
				if(chkArr[currE - '0'] == '\0'){
    				chkArr[currE - '0'] = '1';
    			}else{
    				result = false;
    				break;
    			}
    		}
		}
		if(result == false){
		    break;
		}
	}
	return result;

}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    
    bool result = true;
    char chkArr[10];
    memset(chkArr,'\0',sizeof(chkArr));
    int i,j;
    char currE;

    //check each col
    for(i = 0; i < boardRowSize; i++){
    	for(j = 0; j < boardColSize; j++){
    		currE = board[j][i];

			if(currE != '.'){
    			if(chkArr[currE - '0'] == '\0'){
    				chkArr[currE - '0'] = '1';
    			}else{
    				result = false;
    				break;
    			}
    		}
    	}
    	memset(chkArr,'\0',sizeof(chkArr));
    	if(result == false){
    		break;
    	}
    }
    //check each row
 	if(result == true){
	 	for(i = 0; i < boardColSize; i++){
	    	for(j = 0; j < boardRowSize; j++){
	    		currE = board[i][j];

	    		if(currE != '.'){
		    		if(chkArr[currE - '0'] == '\0'){
		    			chkArr[currE - '0'] = '1';
		    		}else{
		    			result = false;
		    			break;
		    		}
		    	}
	    	}
	    	memset(chkArr,'\0',sizeof(chkArr));
	 		if(result == false){
    			break;
    		}
	    }
	}
    //check each sub-boxes
	
	if(result == true){
		for(i = 0; i < boardColSize; i = i + 3){
			for(j = 0; j < boardRowSize; j = j + 3){
				result = check_sub_box(board,j,i,SUB_ROW_SIZE,SUB_COL_SIZE);
				if(result == false){
					break;
				}
			}
			if(result == false){
				break;
			}
		}	
	}
    return result;
}

/*
[".87654321","2........","3........","4........","5........","6........","7........","8........","9........"]
[".87654321","3........","3........","4........","5........","6........","7........","8........","9........"]
[".87654321","23.......","3........","4........","5........","6........","7........","8........","9........"]
*/