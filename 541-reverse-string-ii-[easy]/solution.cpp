// started 4/21/17 3:38PM - 4:15PM
class Solution {
public:
    string reverseStr(string s, int k) {
       
        if(k <= 0)
            return s;
       
        string leftover, sub_k, result = "";
        vector<string> sub_2k;
        int twok = k * 2;
        int leftover_len;
       
        for(int i = 0; i < s.length(); i = i + twok)
            sub_2k.push_back(s.substr(i, twok));
   
        vector<string>::iterator it;
        for(it = sub_2k.begin(); it != sub_2k.end(); ++it){
            sub_k        = (*it).substr(0, k);
            leftover_len= (*it).length() - sub_k.length();
 
            if(leftover_len > 0)
               leftover = (*it).substr(k, abs((*it).length() - sub_k.length()));
                                                   
               sub_k    = reverse_str(sub_k);
               result   = result + sub_k + leftover;
               leftover = "";
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