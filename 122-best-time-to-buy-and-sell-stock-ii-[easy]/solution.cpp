// 122. Best Time to Buy and Sell Stock II
//started 4/24/17 11:41AM - 11:57AM (stuck)
 
/*
Great solution!!
 
Second, suppose the first sequence is "a <= b <= c <= d", the profit is "d - a = (b - a) + (c - b) + (d - c)" without a doubt.
And suppose another one is "a <= b >= b' <= c <= d", the profit is not difficult to be figured out as "(b - a) + (d - b')".
So you just target at monotone sequences.
 
//http://tutorial.math.lamar.edu/Classes/CalcII/MoreSequences.aspx
*/
 
//TODO: implement faster algorithm
//TODO: understand why the algorithm works, does it cover all the corner cases?, come up with all the cases
//                            read other solutions
//                            read about optimization
 
//TODO: implement local max and local min solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
 
    }
 
};
 
/* //target monotonic sequences
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int profit = 0;
 
        for(int i = 1; i < prices.size(); ++i){                                                                                    
               profit = profit + max(prices[i] - prices[i - 1], 0);
        }
        return profit;
    }
};
*/
 
/*
[1,2,5,2,1,7]
[0,5,3,7,7,10]
[2,3,2,3,2,3,20]
*/