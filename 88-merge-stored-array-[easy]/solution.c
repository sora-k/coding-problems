//started  11/21/16 11:46 pm - 11/22/16 12:51 am 
// NOTE: redo again took too long to solve !!
//		 draw out a plan on a piece of paper!!
//		 NVM printing slows down the program !! 
#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n) {
 	
    int nums1b[m];
    int i;
    for(i = 0; i < m; i++){
        nums1b[i] = nums1[i];
    }
    
    int k = 0, j = 0;
    for(i = 0; i < m + n; i++){
        int num1 = k < m ? nums1b[k] : num1;
        int num2 = j < n ? nums2[j] : num2;
        
        if(k < m && j < n){
            if(num1 < num2){
                nums1[i] = num1;
                k++;
            }else{
                nums1[i] = num2;
                j++;
            }
        }else{
            if(j < n){
                nums1[i] = nums2[j];
                j++;
            }
            if(k < m){
               nums1[i] = nums1b[k];
               k++;
            }
        }
    }
}
/*
[1,0]
1
[2]
1
[1,0]
1
[1]
1
[1]
1
[]
0
[2,2,2,0,0,0]
3
[2,2,2]
3
[1,2,3,0,0,0]
3
[1,2,3]
3
[1,2,4,5,6,0]
5
[3]
1


*/
