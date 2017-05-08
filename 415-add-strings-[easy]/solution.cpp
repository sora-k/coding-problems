// Add strings
// started 3/15/17 9:00PM - 9:39PM

class Solution { // more efficient solution
public:
    string addStrings(string num1, string num2) {
        
        int result_size = num1.length() > num2.length() ? num1.length() : num2.length();
        result_size++;

        string result (result_size, 'x');

        int carry = 0;
        int dig1, dig2, sum, new_dig;
        string::reverse_iterator it1, it2;
        string::iterator it_result;

        it1 = num1.rbegin();
        it2 = num2.rbegin();

        it_result = result.end() - 1;

       for(;it1 != num1.rend(); ++it1){
       		dig1 = *it1 - '0';
        	
        	if(it2 == num2.rend()){
        		sum = dig1 + carry;
        	}else{
	        	dig2   = *it2 - '0';
	        	sum    = dig1 + dig2 + carry;
	        	++it2;
        	}

        	carry  = sum > 9 ? 1 : 0;
	        new_dig= sum > 9 ? sum % 10 : sum;
        	*(it_result--) = (char)(new_dig + '0');
        }
        for(;it2 != num2.rend(); ++it2){
        	dig2 = *it2 - '0';
        	sum  = dig2 + carry;

        	carry  = sum > 9 ? 1 : 0;
	        new_dig= sum > 9 ? sum % 10 : sum;
        	*(it_result--) = (char)(new_dig + '0');
        }
        if(carry > 0)
        	*(it_result) = (char)(carry + '0');

        if(*it_result == 'x')
        	result.erase(it_result);	// <-- can only erase iterator, not reverse_iterator

        return result;
    }
};



/* first solution
class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string result = "";

        int carry = 0;
        int dig1, dig2, sum, new_dig;
        string::reverse_iterator it1, it2;

        it1 = num1.rbegin();
        it2 = num2.rbegin();

       for(;it1 != num1.rend(); ++it1){
       		dig1 = *it1 - '0';
        	
        	if(it2 == num2.rend()){
        		sum = dig1 + carry;
        	}else{
	        	dig2   = *it2 - '0';
	        	sum    = dig1 + dig2 + carry;
	        	++it2;
        	}

        	carry  = sum > 9 ? 1 : 0;
	        new_dig= sum > 9 ? sum % 10 : sum;
        	result = (char)(new_dig + '0') + result;
        }
        for(;it2 != num2.rend(); ++it2){
        	dig2 = *it2 - '0';
        	sum  = dig2 + carry;

        	carry  = sum > 9 ? 1 : 0;
	        new_dig= sum > 9 ? sum % 10 : sum;
        	result = (char)(new_dig + '0') + result;
        }
        result = (carry != 0) ? (char)(carry + '0') + result : result;

        return result;
    }
};
*/