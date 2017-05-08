#include <stdlib.h>

//started attempt1 -> 1/24/17 11:20PM - 12:15AM (time limit exceed)
//started attempt2 -> 1/25/17 6:29PM - 8:19PM (not able to solve it easily)
//started attempt3 -> 1/26/17 7:36PM - 8:30PM

//attempt 3
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

    	std::unordered_map<int,int> hash;

    	int i; 
    	std::unordered_map<int,int>::iterator uit;
    	for(std::vector<int>::iterator it = nums.begin(); it  != nums.end(); ++it){

    		int val = *it;
    		uit = hash.find(val);

    		if(uit == hash.end()){
    			hash.insert({val, i});
    		}else{
    			if(i - uit->second <= k){ 
    				return true;
    			}else{
    				hash.erase(val);
    				hash.insert({val, i});
    			}
    		}
    		i++;
    	}
    	return false;

};
};

/*
class Solution {	//sudo code
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

    	std::unordered_map hash;

    	for(i to nums.size - 1){
    		if(hash.contains(nums[i]) == false){
    			hash.insert(nums[i], i);
    		}else{
    			if(i - hash.get(nums[i]) <= k){
    				return true;
    			}else{
    				hash.remove(nums[i]);
    				hash.insert(nums[i],i);
    			}
    		}
    	}
    }
};
*/

/* attempt 2 (not able to solve it easily)

struct Element{
	int val;
	int originalInd;
};
void swap(struct Element *a,struct Element *b){

	int tmpVal = (*a).val;
	int tmpOr = (*a).originalInd;

	(*a).val = (*b).val;
	(*a).originalInd = (*b).originalInd;

	(*b).val = tmpVal;
	(*b).originalInd = tmpOr;

}
int partition(struct Element *nums, int start, int end){

	if(start >= end){
		return;
	}

	int cnt = (end - start) + 1;
	int pivE = nums[rand() % cnt + start].val;

	while(start < end){
		
		while(nums[start].val < pivE) start++;      //NOTE TO SELF: switching comparison signs reverse the sorting order
		
		while(nums[end].val > pivE) end--;

		if(start < end){
			swap(&(nums[start]),&(nums[end]));
			start++;
			end--;
		}
	}
	return start;
}
void quick_sort_helper(struct Element *nums, int start, int end){

	int piv = partition(nums, start, end);

	if(start < piv - 1){
		quick_sort_helper(nums, start, piv - 1);
	}
	if(end > piv){
		quick_sort_helper(nums, piv, end);
	}

}
void quick_sort(struct Element *nums, int size){

	time_t t;
	srand((unsigned) time(&t));

	quick_sort_helper(nums, 0, size - 1);

}
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
   
	struct Element *sortedNums = (struct Element *)malloc(sizeof(struct Element) * numsSize);

	for(int i = 0; i < numsSize; i++){
		sortedNums[i].val = nums[i];
		sortedNums[i].originalInd = i;
	}
	quick_sort(sortedNums,numsSize);

    for(int i = 0; i < numsSize; i++){
        
        int val = sortedNums[i].val;
       	int ...
    }
	printf("\n");
	free(sortedNums);
	
	return false;
   //sort nums into separate array, sortedNums
   //map sortedNums to real index in nums, mapToNums
   //traverse through nums and do binary search in sortedNums, if duplicate is found in sortedNums, do adjacent search and compute diff in indices from real indices
}
*/
/*
[]
0
[1]
0
[2]
0
[1,2,2,1]
0
[1,3,3,4,1]
0
[1,3,4,1]
0
[5,4,3,2,1]
0
[5,4,3,9,1,0]
0
*/

//NOTE: TIme limit exceed as expected!!
/*
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    
    if(k > 0){
        for(int i = 0; i < numsSize; i++){
        	
        	int curE = nums[i];
        	int diff = k;
        	
        	while(diff > 0){
        		int ind = i + diff;
    
        		if(ind < numsSize){
        			if(nums[ind] == curE) return true;
        		}
        		diff--;
        	}
        }
    }
    return false;
}
*/