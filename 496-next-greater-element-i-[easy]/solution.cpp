//496. Next Greater Element I
// 4/16/17 8:30PM - 9:21PM
class Solution {
	public:
	    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
	        
	        vector<int> result;
	        
	        int x;
	        unordered_map<int, int> map;
	        vector<int>::iterator it, it2;
	        
	        for(int i = 0; i < nums.size(); ++i)
	        	map.insert({nums[i], i});
	        
	        for(it = findNums.begin(); it != findNums.end(); ++it){
	        	x = -1;
	        	for(it2 = nums.begin() + map[*it]; it2 <= nums.end() - 1; ++it2){
	        		if(*it2 > *it){
	        			x = *it2;
	        			break;
	        		}
	        	}
	        	result.push_back(x);
	        }
	        return result;
	 }
	
};