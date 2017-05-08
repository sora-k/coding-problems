//started 2/26/17 10:40PM - 10:53PM

// optimized solution
class Solution {
public:
   bool canConstruct(string ransomNote, string magazine) {
            
        bool result = true;
        int char_cnt[255];

        for(int i = 0; i < 255; ++i){
            char_cnt[i] = 0;
        }

        for(int i = 0; i < magazine.length(); ++i){
            char c = magazine[i];
            char_cnt[c]++;
        }

        for(int i = 0; i < ransomNote.length(); ++i){
          char c = ransomNote[i];
          if(char_cnt[c] == 0){
              result = false;
              break;
          }else{
              char_cnt[c]--;
          }
        }
        return result;
    }
};

// TODO: optimize read and write, too slow
/*
class Solution {
public:
       bool canConstruct(string ransomNote, string magazine) {
               
               bool result = true;
               unordered_map<char, int> char_cnt_map;

               for(int i = 0; i < magazine.length(); ++i){
                       char c = magazine[i];
                       
                       if(char_cnt_map.find(c) != char_cnt_map.end()){
                               char_cnt_map[c]++;
                       }else{
                               char_cnt_map.insert({c, 1});
                       }
               }

               for(int i = 0; i < ransomNote.length(); i++){
                       char c = ransomNote[i];

                       if(char_cnt_map.find(c) != char_cnt_map.end()){
                               if(char_cnt_map[c] != 0){
                                       char_cnt_map[c]--;
                               }else{
                                       result = false;
                                       break;
                               }
                       }else{
                               result = false;
                               break;
                       }
               }
               return result;
       }
};
*/