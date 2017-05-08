// started 11/27/16 12:38AM - 1:19AM
/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    
    int **result = (int **)malloc(sizeof(int *) * numRows);
    *columnSizes = (int *)malloc(sizeof(int) * numRows);

    result[0] = (int *)malloc(sizeof(int));
    result[0][0] = 1;
    (*columnSizes)[0] = 1;

    int i,k,l;
    for(i = 1 ; i < numRows; i++){
        
         int *prevRow = result[i - 1];     
         int prevRowSize =  (*columnSizes)[i - 1];

         int rowSize = i + 1;
         int *newRow = (int *)malloc(sizeof(int) * rowSize);
         result[i]  = newRow;
         (*columnSizes)[i] = rowSize;    

         l = 0;       
         for(k = 0; k < rowSize; k++){
            if(l == 0 || l == prevRowSize ){
                 newRow[k] = 1;
            }else{
                newRow[k] = prevRow[l - 1] + prevRow[l];
            }
            l = (l < prevRowSize)? l + 1 : l;
         }
    }
    return result;
}