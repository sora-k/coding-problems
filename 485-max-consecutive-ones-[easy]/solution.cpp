//485. Max Consecutive Ones
//4/16/17 7:26PM - 7:33PM

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int result = 0;
        int count  = 0;
        
        vector<int>::iterator it;
        for(it = nums.begin(); it != nums.end(); ++it){
        	if(*it == 0){
        		result = result < count ? count : result;
        		count  = 0;
        	}else{
        		count++;
        	}
        }
        result = result < count ? count : result;
        return result;
    }
};