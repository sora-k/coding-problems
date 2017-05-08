// 11/30/16 started again 8:10 am

void merge_sort(int *arr,int start, int end, int size){
	
	if(start >= end){
		return;
	}
	int middle = (end + start)/2;
	merge_sort(arr,start,middle,size);
	merge_sort(arr,middle + 1, end,size);
	merge(arr,start,end,size);

}
void merge(int *arr,int start, int end, int size){
	
	int middle = (end + start)/2;
	int *tmpArr = (int *)malloc(sizeof(int)*size);
	int i,j,k;
	for(i = start; i < end + 1; i++){
		tmpArr[i] = arr[i];
	}
	k = start;
	i = start; 
	j = middle + 1;
	while(i < middle + 1){
		if(j < end + 1){
			int currL = tmpArr[i];
			int currR = tmpArr[j];
			if(currL <= currR){
				arr[k] = currL;
				i++;
			}
			if(currR < currL){
				arr[k] = currR;
				j++;
			}
		}
		else{
			arr[k] = tmpArr[i];
			i++;
		}
		k++;
	}
	while(j < end + 1){
		arr[k] = tmpArr[j];
		j++;
		k++;
	}
	free(tmpArr);
}
int find_max(int* arr, int start, int size, int *maxInd){
	
	if(start >= size){
		*maxInd = -1;
		return 0;
	}

	int max = arr[start];
	*maxInd = start;
    
	int i;
	for(i = start + 1; i < size; i++){
		*maxInd = (arr[i] > max) ? i : *maxInd;
		max = (arr[i] > max) ? arr[i] : max;
	}
	
	return max;

}
int maxProfit(int* prices, int pricesSize) {
    
	int maxProf = 0;

	int maxInd;
	int max = find_max(prices,1, pricesSize, &maxInd);
	
	int i;
	for(i = 0; i < pricesSize; i++){
		if(maxInd <= i){
			max = find_max(prices,i + 1, pricesSize, &maxInd);
		}
		if(maxInd > i){
			int curPrice = prices[i];
			if(curPrice < max){
				int diff = max - curPrice;
				maxProf = (diff > maxProf) ? diff : maxProf;
			}
		}
	}
    return maxProf;
}