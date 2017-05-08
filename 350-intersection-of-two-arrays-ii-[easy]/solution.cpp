// started 2/20/17 2:01AM - 2:14AM

class Solution {
public:
   vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       
       vector<int>             result;
       unordered_map<int, int> num_map;
       vector<int>::iterator   it;

       for(it = nums1.begin(); it != nums1.end(); ++it){
           if(num_map.find(*it) == num_map.end()){
               num_map.insert({*it, 1});
           }else{
               num_map[*it]++;
           }
       }
       for(it = nums2.begin(); it != nums2.end(); ++it){
           if(num_map.find(*it) != num_map.end()){
               if( 0 < num_map[*it]--){
                   result.push_back(*it);
               }
           }
       }
       return result;
   }
};
