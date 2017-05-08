//started 2/19/17 4:33PM - 4:45PM
class Solution {
public:
   string reverseString(string s) {
	   
	   for(int i = 0, j = s.size() - 1; i < j; ++i, --j){
	       char tmp = s[i];
	       s[i]         = s[j];
	       s[j]         = tmp;
	   }
       return s;
   }
};

/*
"a"
"ab"
"abc"
"abcd"
"hello"
*/