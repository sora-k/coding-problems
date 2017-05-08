// started 4/21/17 1:55PM - 2:10PM
class Solution {
public:
    bool detectCapitalUse(string word) {
      
       bool rule_1 = false;  // All letters in this word are capitals, like "USA".
       bool rule_2 = false; // All letters in this word are not capitals, like "leetcode".
       bool rule_3 = false; // Only the first letter in this word is capital if it has more than one letter, like "Google".
       int  capitalCnt = 0;
      
       string::iterator it = word.begin();
       for(it = word.begin(); it != word.end(); ++it){
                               if(isupper(*it))
                                               capitalCnt++;
       }
       rule_3 = isupper(*(word.begin())) && (capitalCnt == 1);
       rule_2 = (capitalCnt == 0);
       rule_1 = (capitalCnt == word.size());
 
       return rule_3 || rule_2 || rule_1;
    }
};
 
/*
"USA"
"helloworld"
"Hellowrodl"
"helloWorld"
"HelloWorld"
"HELLOWORLD"
"FlaG"
*/