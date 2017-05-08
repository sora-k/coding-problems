// FizzBuzz
// started 3/15/17 7:26PM - 7:37PM

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> result;

        string current_str;
        for(int i = 1; i < n + 1; ++i){
        	current_str = "";
            
        	if(i % 3 != 0 && i % 5 != 0)
	        	current_str = std::to_string(i);    	
        	if(i % 3 == 0)
        		current_str = "Fizz";
        	if(i % 5 == 0)
        		current_str += "Buzz";

        	result.push_back(current_str);
        }
        return result;

    }
};