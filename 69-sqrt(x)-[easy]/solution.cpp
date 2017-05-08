// 4/22/17 10:00PM - 10:20PM (stuck)
//TODO: proof that this returns the expected result, when left == right
//TODO: study binary search, how left and right pointer move with respect to 
//			1. comparisions between middle and target
//			2. indices (left = 0 and right = x) vs. (left = 1 and right = x)
//			3. (left = middle + 1 and right = middle - 1) vs. (left = middle + 1 and right = middle)
//		prove that the algorithm covers all elements
//		implement variation of binary search !!
//          - try 2 elements
//          - try 3 elements
//          - try with odd  number of elements , see if you could reach all elements in the array
//          - try with even number of elements , see if you could reach all elements in the array
//              

class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 0)
        	return 0;
        if(x < 0)
        	return -2147483648;

        int left  = 1;
        int right = x;
        int middle, result;

        while(left <= right){
        	middle = left + (right - left) / 2;

        	if(middle <= x/middle){
        		left   = middle + 1;
        		result = middle;
        	}else{
        		right = middle - 1;
        	}
        }

        return result;
    }
};