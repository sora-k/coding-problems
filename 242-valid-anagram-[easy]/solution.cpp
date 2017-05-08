//started 2/6/17 11:21PM - 11:41PM
class Solution {
public:
   bool isAnagram(string s, string t) {
           
           std::unordered_map<char,int> hashS;
       int charCnt = s.size();
       
           for(char& c : s){
                   if(hashS.find(c) == hashS.end()){
                           hashS[c] = 1;
                   }else{
                           hashS[c] = hashS[c] + 1;
                   }
           }
           for(char& c : t){
                   if(hashS.find(c) == hashS.end()){  // if char isn't found, return false
                           return false;
                   }else{
                           hashS[c] = hashS[c] - 1;                // substract count

                           if(hashS[c] < 0){
                                   return false;
                           }
                   }
                   charCnt--;
           }
       return charCnt == 0;
   }
};


/*
"ABC"
"CBA"
"123"
"321"
"®abc"
"bac®"
"®abcx"
"bac®"
*/
