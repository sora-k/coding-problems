// Third Maximum Number
// started 3/15/17 7:41PM - 8:40PM

// TODO: took too long!! read the code carefully for bugs!!

#include <climits>

class Solution {
public:
    int thirdMax(vector<int>& nums) {
       	
       	int  result[] = {INT_MIN, INT_MIN, INT_MIN};
    	bool update[] = {false, false, false};

        vector<int>::iterator it;
        for(it = nums.begin(); it != nums.end(); ++it){	//find first max
        	if(*it >= result[0]){
        		result[0] = *it;
        		update[0] = true;
        	}
        }	
        for(it = nums.begin(); it != nums.end(); ++it){ //find second max
        	if(*it >= result[1] && *it != result[0]){
        		result[1] = *it;
        		update[1] = true;
        	}
        }	

		for(it = nums.begin(); it != nums.end(); ++it){ // find third max
			if(*it >= result[2] && *it != result[0] && *it != result[1]){
				result[2] = *it;
				update[2] = true;
			}	        
		}	
        if(update[2] == false)
        	return result[0];

        return result[2]; // <-- was nums[2], hard to notice if don't read code carefully
    }
};