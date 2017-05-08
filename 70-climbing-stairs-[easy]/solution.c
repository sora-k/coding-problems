//started 11/20/16 1:49 am - 11:48pm
#include <stdio.h>

void arr_init(int *arr, int size, int val){

	int i;
	for(i = 0; i < size; i++){
		arr[i] = val;
	}

}
int climb_recurs(int n, int *arr){

	if(n <= 1){
		return 1;
	}
	if(arr[n - 1] == -1){
		arr[n-1] = climb_recurs(n - 1, arr);
	}
	if(arr[n - 2] == -1){
		arr[n - 2] = climb_recurs(n - 2, arr);
	}
	return arr[n - 1] + arr[n -2];
}

/* naive algorithm
int climb_recurs(int cur, int n){

	if(cur == n){
		return 1;
	}
	if(cur < n){
		return climb_recurs(cur + 1, n) + climb_recurs(cur + 2,n);
	}
	return 0;
}
*/
int climbStairs(int n) {
    
    int arrSize = n + 1;
    int arr[arrSize];
    arr_init(arr,arrSize,-1);

    return climb_recurs(n,arr);

}

/*
-1
0
1
2
4
5
6
7
8
9
10
*/