// started 4/22/17 6:51PM - 7:05PM
//				   7:11PM - 7:45PM

// TODO: took too long, read to better understand problem https://en.wikipedia.org/wiki/Absolute_difference
//		 study solution for insight

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int result = 0;
        int diff1, diff2;

        if(k < 0)
        	return 0;

        unordered_map<int, int> value_map;

        vector<int>::iterator it;
        for(it = nums.begin(); it != nums.end(); ++it){
        	if(value_map.find(*it) == value_map.end())
        		value_map.insert({*it, 1});
        	else
        		value_map[*it]++;
        }
        for(it = nums.begin(); it != nums.end(); ++it){
        	diff1 = *it - k;
        	diff2 = *it + k;

        	if((diff1 != diff2) && (value_map[*it] > 0)){
	        	if((value_map.find(diff1) != value_map.end()) && (value_map[diff1] > 0))
	        		++result;

	        	if((value_map.find(diff2) != value_map.end()) && (value_map[diff2] > 0))
	        		++result;
	        	
	        	value_map[*it] = 0;
	        }else{
	        	if(value_map[*it] >= 2){
	        		value_map[*it] = 0;
	        		++result;
	        	}
	        }
        }

        return result;
    }
};

/*
[3,1,4,1,5]
2
[1, 3, 1, 5, 4]
0
[1, 2, 3, 4, 5]
1
[1,2,3,4,5]
-1
[1,1,1,2,1]
1
*/