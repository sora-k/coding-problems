// started 2/19/17        5:00PM - 6:00PM
//                        1:20PM - 1:30PM
using std::unordered_map;

class Solution {
public:
       string reverseVowels(string s) {
       
       int i = 0;
       int j = s.size() - 1;

       while(i < j){
           while((vowel_.find(s[i]) == vowel_.end()) && i < j) ++i;
           
           while((vowel_.find(s[j]) == vowel_.end()) && i < j) --j;
               
           if(i < j){
               char tmp  = s[i];
               s[i] = s[j];
               s[j] = tmp;
               i++;
               j--;
           }
       }
       return s;
   }
private:
       unordered_map<char, bool> vowel_ = {{'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true}, {'A', true}, {'E', true}, {'I', true}, {'O', true}, {'U', true}};
};


