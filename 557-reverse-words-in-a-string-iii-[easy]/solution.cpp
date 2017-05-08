//started 4/21/17 4:18PM - 4:38PM
 
//TODO: comeup with a faster solution, string builder?
//                            read faster solutions
 
class Solution {
public:
    string reverseWords(string s) {
       
        string sub_str, result = "";
 
        int start_ind = 0;
        int sub_size  = 0;
        int  i                                 = 0;
        string::iterator it;
        for(it = s.begin(); it != s.end(); ++i, ++it){
           if(*it == ' '){
               sub_str  = s.substr(start_ind, i - start_ind);
               start_ind= i + 1;
               sub_str  = reverse_str(sub_str) + *it;
               result = result + sub_str;
           }
        }
        if(start_ind < s.length()){
           sub_str  = s.substr(start_ind, i - start_ind);
           start_ind= i + 1;
           sub_str  = reverse_str(sub_str);
           result   = result + sub_str;
        }
        
        return result;
    }
private:
    string reverse_str(string s){
       
        string result = "";

        string::reverse_iterator rit;
        for(rit = s.rbegin(); rit != s.rend(); ++rit)
            result = result + *rit;

        return result;
    }
};
