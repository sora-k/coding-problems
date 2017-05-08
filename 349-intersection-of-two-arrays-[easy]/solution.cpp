//started 2/20/17 1:37AM - 1:47AM

//O(nums1.size + nums2.size) - runtime
//O(nums2.size) - space
class Solution {
public:
   vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       
       vector<int>                 result;
       unordered_map<int,char> mapNum2;
       vector<int>::iterator         it;
       
       for(it = nums2.begin(); it != nums2.end(); ++it){
           if(mapNum2.find(*it) == mapNum2.end()){
               mapNum2.insert({*it, 'T'});
           }
       }
       for(it = nums1.begin(); it != nums1.end(); ++it){
           if(mapNum2.find(*it) != mapNum2.end()){
               if(mapNum2[*it] == 'T'){
                   result.push_back(*it);
                   mapNum2[*it] = 'N';
               }
           }
       }
       return result;
   }
};

// O(min(nums1.size, nums2.size) - space
/*
class Solution {
public:
   vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       
       vector<int>                         result;
       unordered_map<int,char> mapNum2;
       vector<int>::iterator         it;
       vector<int> *ptr_map, *ptr_target;

       ptr_map   = nums1.size() < nums2.size() ? &nums1 : &nums2;
       ptr_target= nums1.size() < nums2.size() ? &nums2 : &nums1;

       for(it = ptr_map->begin(); it != ptr_map->end(); ++it){
               if(mapNum2.find(*it) == mapNum2.end()){
                       mapNum2.insert({*it, 'T'});
               }
       }
       for(it = ptr_target->begin(); it != ptr_target->end(); ++it){
               if(mapNum2.find(*it) != mapNum2.end()){
                       if(mapNum2[*it] == 'T'){
                               result.push_back(*it);
                               mapNum2[*it] = 'N';
                       }
               }
       }
       return result;
   }
};
*/