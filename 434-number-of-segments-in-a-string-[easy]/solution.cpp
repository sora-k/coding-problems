// Number of Segments in a String

// started 3/19/17 12:27PM - 12:49PM
class Solution {
public:
    int countSegments(string s) { //O(n)
        
        int result 		= 0;
        bool in_segment = false;

        string::iterator it;
        for(it = s.begin(); it != s.end(); ++it){
        	if(in_segment == false){
        		in_segment = (*it != ' ') ? true : false;
        		result	   = (in_segment) ? result + 1 : result;
        	}
        	else
        		in_segment = (*it == ' ') ? false : true;
        }
        return result;
    }
};