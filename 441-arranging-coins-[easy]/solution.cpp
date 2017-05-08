// 441. Arranging Coins
// started 4/1/17 10:16PM - 10:38PM (bruteforce)
// TODO: improve efficency - study these solutions 
//						   - https://discuss.leetcode.com/topic/65593/java-clean-code-with-explanations-and-running-time-2-solutions/2
//						   - https://discuss.leetcode.com/topic/65631/c-three-solutions-o-n-o-logn-o-1

// close form for arithmatic sum
// 1 + 2 + 3 + 4 + 5 +...+ x => (x + 1) + ((x - 1) + 2) + ... => (x + 1) * x/2 pairs => x(x + 1)/2

//math approach (solving arithmatic sum, use quadratic equation)
class Solution {
public:
    int arrangeCoins(int n) {
        
        int result = 0;
       	
       	//... 
       
        return result;
    }
};
//binary search approach (...)
class Solution {
public:
    int arrangeCoins(int n) {
        
        int result = 0;
        
        //...
              
        return result;
    }
};

//bruteforce approach
class Solution {
public:
    int arrangeCoins(int n) {
        
        int result = 0;
        
        if(n < 0)
            return -1;
                                //order matters
        for(int i = 1; i <= n;  n -= i, i++)
        	result++;

        return result;
    }
};