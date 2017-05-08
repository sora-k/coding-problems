//TODO: study a faster solution, or do a binary search solution
// 167. Two Sum II - Input array is sorted
//started 4/24/17 11:08AM - 11:30AM
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) { //O(N) - space, O(2N) - time
       
        vector<int> result;
        unordered_map<int, int> num_cnt_map;
 
        vector<int>::iterator it;
        for(it = numbers.begin(); it != numbers.end(); ++it){
           if(num_cnt_map.find(*it) == num_cnt_map.end())
               num_cnt_map.insert({*it, 1});
           else
               num_cnt_map[*it]++;
        }
 
        int  find, sub_targ,  i = 0;
        bool found = false;
        for(it = numbers.begin(); it != numbers.end(); ++it, ++i){
            num_cnt_map[*it]--;

            if(found == false){
                sub_targ = target - *it;
                if(num_cnt_map.find(sub_targ) != num_cnt_map.end() && num_cnt_map[sub_targ] > 0){
                    result.push_back(i + 1);
                    find  = sub_targ;
                    found = true;
                }
            }else{
                if(*it == find){
                    result.push_back(i + 1);
                    break;
                }
            }
        }
        return result;
    }
};