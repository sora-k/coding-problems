//2/27/17 9:47PM - 10:10PM
class Solution {
public:
   char findTheDifference(string s, string t) {
       
     char result = ' ';
     int char_cnt[255];
     
     for(int i = 0; i < 255; ++i){
         char_cnt[i] = 0;
     }
     for(int i = 0; i < s.length(); ++i){
         char_cnt[s[i]]++;
     }
     for(int i = 0; i < t.length(); ++i){
         char c = t[i];
         
         if(char_cnt[c]-- == 0){
             result = c;
             break;
         }
     }
     return result;
   }
};

/*
"abcd"
"dcbaw"
"abcd"
"akbcd"
"a"
"aa"
*/