// 492. Construct the Rectangle
// started 4/16/17 7:35PM - 7:52PM
#include <limits.h>
class Solution {
public:
    vector<int> constructRectangle(int area) {
        
        vector<int> result;

        int length = 0, width = 0;
        int difference = INT_MAX;

        int divisor  = 1;
        int quotient = area / divisor;
        int remainder= area % divisor;

        while(divisor <= quotient){
        	if(remainder == 0){
        		if(abs(divisor - quotient) < difference){
        			difference= abs(divisor - quotient);
        			length 	  = quotient;
        			width	  = divisor;
        		}
        	}
        	divisor++;
        	remainder= area % divisor;
        	quotient = area / divisor;
        }
        result.push_back(length);
        result.push_back(width);
        return result;
    }
};