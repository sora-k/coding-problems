// 459. Repeated Substring Pattern
//started 4/11/17 12:12AM - 12:53AM (stuck)
//				  6:00PM  - 7:09PM
//TODO: study efficient solution!
//		took too long!!

//TODO: study KMP string matching algorithm
//  https://www.youtube.com/watch?v=5i7oKodCRJo
//	https://www.ics.uci.edu/~eppstein/161/960227.html
//  https://www.youtube.com/watch?v=GTJr8OvyEVQ

//TODO: implement your own KMP algorithm
//  then study --> https://discuss.leetcode.com/topic/67652/c-o-n-using-kmp-32ms-8-lines-of-code-with-brief-explanation
class Solution {
public:
    bool repeatedSubstringPattern(string s) { //O(1000 * 1000)
        
        bool result = false;
      
        if(s.size() <= 1)
        	return result;

        int substr_size = 1;
        int	start_ind	= 0;
        while(substr_size < s.size() && result == false){	//O(1000)
        	string substr (s, 0, substr_size);
        	start_ind = substr_size;
        	result	  = true;
        	
        	while(start_ind < s.size() && result == true){ //O(1000)
        	    //cout<<"start_ind:"<<start_ind<<" - ";
        		string substr2 (s, start_ind, substr_size);
        		start_ind  = start_ind + substr_size;
        		result    &= (substr.compare(substr2) == 0);
                //cout<<"result:"<<result<<" "<<substr<<":"<<substr2<<endl;
        	}
        	substr_size = substr_size + 1;
        }
        return result;
    }
};
//"abcdefg" -> a , ab, abc, abcd, abcde, abcdef, abcdefg
/*
"a"
"aba"
"abcabcabcabc"
"aabaaba"
*/