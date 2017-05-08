// started 4/21/17 10:07AM - 10:30AM (not as efficient)
 
class Solution { //more efficient O(n)
public:
    string convertToBase7(int num) {
                               
        int  result   = 0;
        int  mult     = 1;
        bool negative = num < 0 ? true : false;
        int rem       = 0;
        num           = abs(num);

        while(num > 0){
            rem    = num % 7;
            num    = num / 7;
            result = result + (rem * mult);
            mult   = mult * 10;
        }
        if(negative == true)
            result = result * -1;

        return std::to_string(result);
    }         
};
 
/*
class Solution { //not as efficient O(n^2) create new string everytime
public:
    string convertToBase7(int num) {
                               
        string result = num == 0 ? "0" : "";
        bool negative = num < 0 ? true : false;
        int rem       = 0;
        num           = abs(num);

        while(num > 0){
            rem    = num % 7;
            num    = num / 7;
            result = std::to_string(rem) + result;
        }
        if(negative == true)
            result = "-" + result;

        return result;
    }         
};
*/