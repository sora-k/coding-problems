// 500. Keyboard Row
// 4/16/17 9:28PM - 9:48PM
#include <ctype.h>
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        vector<string> result;

        unordered_map<char, char> map_row1 = {{'q','0'},{'w','0'},{'e','0'},{'r','0'},{'t','0'},{'y','0'},{'u','0'},{'i','0'},{'o','0'},{'p','0'}};
        unordered_map<char, char> map_row2 = {{'a','0'},{'s','0'},{'d','0'},{'f','0'},{'g','0'},{'h','0'},{'j','0'},{'k','0'},{'l','0'}};
        unordered_map<char, char> map_row3 = {{'z','0'},{'x','0'},{'c','0'},{'v','0'},{'b','0'},{'n','0'},{'m','0'}};

        bool valid1, valid2, valid3;
        string::iterator it;
        vector<string>::iterator str_it;
        for(str_it = words.begin(); str_it != words.end(); ++str_it){
        	valid1 = true, valid2 = true, valid3 = true;
        	for(it = (*str_it).begin(); it != (*str_it).end(); ++it){
        		if(map_row1.find(tolower(*it)) == map_row1.end()){
        			valid1 = false;
        		}
        		if(map_row2.find(tolower(*it)) == map_row2.end()){
        			valid2 = false;
        		}
        		if(map_row3.find(tolower(*it)) == map_row3.end()){
        			valid3 = false;
        		}
        	}
        	if(valid1 == true || valid2 == true || valid3 == true)
        		result.push_back(*str_it);
        }
        return result;
    }
};
