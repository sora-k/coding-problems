// started 3/14/17 10:07AM - 10:33PM (stuck)
//                 11:00AM - 12:00PM
class Solution {  //error at "bananas"
public:
    int longestPalindrome(string s) {
       
       int result = 0;
  
       unordered_map<char, int> char_cnt_map;
       std::string::iterator it;
 
       // cnt individual letters
       for(it = s.begin(); it != s.end(); ++it){
           if(char_cnt_map.find(*it) == char_cnt_map.end())
               char_cnt_map.insert({*it, 1});
           else
               char_cnt_map[*it]++;
        }
        /*  NOTE to self:
              check for different types of palindrome
              type 0 - a
              type 1 - aaaaa     
              type 2 - abccba all even group
              type 3 - abcxcba               one letter
              type 4 - abcacba               one odd group
        */
        // sum letters with even number that letter
        int even_letters_grp_cnt = 0;
        for(it = s.begin(); it != s.end(); ++it){
            if(char_cnt_map[*it] >= 2){
                 even_letters_grp_cnt  += (char_cnt_map[*it] / 2) * 2;
                 char_cnt_map[*it]      = char_cnt_map[*it] % 2;
            }
        }
        // find one letter
        for(it = s.begin(); it != s.end(); ++it){
           if(char_cnt_map[*it] == 1){
               result += 1;
               break;
           }
        }
        result += even_letters_grp_cnt;

        return result;
    }
};
 
/*
"abccccdd"
"bananas"
"aaaaa"
"abccba"
"abcxcba"
"abcacbaccccc"
*/