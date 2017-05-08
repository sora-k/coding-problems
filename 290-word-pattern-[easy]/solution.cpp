//started 2/12/17 2:56PM - 4:09 (stuck)
//        4:19PM - 5:00 PM

//TODO: clean up code, took too long!!, redo!!                                 

class Solution {
public:
   bool wordPattern(string pattern, string str) {
       
       if(!(pattern.size() != 0 && str.size() != 0)){
           return false;
       }

       std::unordered_map<char, string> hash_map_x_y;
       std::unordered_map<string, char> hash_map_y_x;
       std::string::iterator it_p;
       std::vector<string> str_vec =  splitString(str,' ');
       std::vector<string>::iterator it_v;

       for(it_v = str_vec.begin(), it_p = pattern.begin(); it_p != pattern.end() && it_v != str_vec.end(); ++it_p, ++it_v){

           std::unordered_map<char, string>::const_iterator it_h_xy = hash_map_x_y.find(*it_p);
           std::unordered_map<string, char>::const_iterator it_h_yx = hash_map_y_x.find(*it_v);

           if(it_h_xy == hash_map_x_y.end() && it_h_yx == hash_map_y_x.end()){
               hash_map_x_y.insert({*it_p, *it_v});
               hash_map_y_x.insert({*it_v, *it_p});
           }else{
               if(it_h_xy == hash_map_x_y.end() || it_h_yx == hash_map_y_x.end()){
                   return false;
               }
               if(it_h_xy->first != it_h_yx->second){
                   return false;
               }
           }
       }
       
       return it_p == pattern.end() && it_v == str_vec.end();
   }
   std::vector<string> splitString(string str, char delimiter){

       std::vector<string> result;
       std::string::iterator it;
       int start = 0, count = 0;

       for(it = str.begin(); it != str.end(); ++it){
           if(*it == delimiter || it == str.end() - 1){
               count = (it == str.end() - 1) ? count + 1 : count;
               string sub_str = str.substr(start, count);
               result.push_back(sub_str);
               
               start = start + count + 1;
               count = 0;
           }else{
               ++count;
           }
       }
       return result;
   }
};
