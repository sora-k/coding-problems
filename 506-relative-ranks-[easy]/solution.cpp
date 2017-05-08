//started 4/21/17 10:42AM - 11:53AM
 
//TODO: took too long!!, read the problem carefully, run multiple test cases, don't jump to conclusion
//      rank scores first, then assign medal and rank to score.
 
bool compare_func(int i, int j) { return i > j; }
 
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) { //time O(nlogn), space O(3n)
       
       vector<string> result;
       vector<string> awards = {"Gold Medal", "Silver Medal", "Bronze Medal"};
       unordered_map<int, int> score_award_map;
       vector<int> sorted_nums (nums);
       int max;
 
       std::sort(sorted_nums.begin(), sorted_nums.end(), compare_func); //O(nlogn)
              
       int rank = 0;
       vector<int>::iterator it;
       for(it = sorted_nums.begin(); it != sorted_nums.end(); ++it){   //O(n)
           if(score_award_map.find(*it) == score_award_map.end()){
               score_award_map.insert({*it, rank});
               rank++;
           }
       }
       int my_rank;
       for(it = nums.begin(); it != nums.end(); ++it){                //O(n)
           my_rank = score_award_map[*it];
           if(my_rank < awards.size())
                result.push_back(awards[my_rank]);
           else
               result.push_back(std::to_string(my_rank + 1));
       }

       return result;
    }
};
/*
[5,4,3,2,1]
[10,3,8,9,4]
[2,2,2]
[5,2]
*/