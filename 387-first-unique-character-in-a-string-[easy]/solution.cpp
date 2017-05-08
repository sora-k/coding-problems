//2/27/17 9:21PM - 9:35PM


class Solution {
public:
   int firstUniqChar(string s) {
         
     int result = -1;
     int char_cnt[255];

     for(int i = 0; i < 255; ++i){
         char_cnt[i] = 0;
     }
     for(int i = 0; i < s.length(); ++i){
         char_cnt[s[i]]++;
     }
     for(int i = 0; i < s.length(); ++i){
         if(char_cnt[s[i]] == 1){
             result = i;
             break;
         }
     }
     return result;
   }
};
