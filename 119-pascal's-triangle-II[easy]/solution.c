// 11/28/16 (planning) 10:00PM - 10:30 PM
// 11/29/16 (coding) 10:58PM - 11:06PM
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void array_cpy(int *src, int *dst, int start, int end){

    int i;
    for(i = start ; i < end + 1; i++){
        dst[i] = src[i];
    }

}
int* getRow(int rowIndex, int* returnSize) {
    
    int elementCnt = rowIndex + 1;
    int *resultArr = (int *)malloc(sizeof(int) * elementCnt);
    *returnSize = elementCnt;

    int tmpArr[elementCnt];
    int i,l;
    for(i = 0; i < elementCnt; i++){
        for(l = 0; l < i + 1; l++){
            if(l == 0 || l == i){
                resultArr[l] = 1;
                tmpArr[l] = 1;
            }else{
                resultArr[l] = tmpArr[l - 1] + tmpArr[l];
            }
        }
        array_cpy(resultArr,tmpArr,0,i);
    }
    return resultArr;
}