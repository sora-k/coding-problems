//started 4/21/17 2:13PM - 2:59PM
class Solution { //wow
public:
    int findLUSlength(string a, string b) {
        if(a.compare(b) == 0)
               return -1;
        int result = a.length() < b.length() ? b.length() : a.length();
        return result;
    }
};
/*
class Solution {
public:
    int findLUSlength(string a, string b) {
       
        int result = -1;
        int sub_size;
        vector<string> subseq_a;
        unordered_map<string, char> map_sub_b;
        unordered_map<string, char> map_sub_a;
 
        generate_subseq(map_sub_b, b);
        generate_subseq(map_sub_a, a);
 
        unordered_map<string, char>::iterator it;
        for(it = map_sub_a.begin(); it != map_sub_a.end(); ++it){
           if(map_sub_b.find(it->first) == map_sub_b.end()){
               sub_size = (it->first).size();
               result = result < sub_size ? sub_size : result;
           }
        }
       
        for(it = map_sub_b.begin(); it != map_sub_b.end(); ++it){
           if(map_sub_a.find(it->first) == map_sub_a.end()){
              sub_size = (it->first).size();
              result = result < sub_size ? sub_size : result;
           }
        }
        return result;
    }
private:
     void generate_subseq(unordered_map<string, char>& map, string s){
 
        string sub_str = "";
        string::iterator it;
        for(it = s.begin(); it != s.end(); ++it){
               sub_str = sub_str + *it;
               map.insert({sub_str, '/0'});
        }
    }
};
*/
/*
"aaa"
"a"
"aba"
"cdc"
"a"
"a"
""
""
"abxd"
""
""
"asdfsdfds"
*/