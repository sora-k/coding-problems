//476. Number Complement
//started 4/16/17 6:05PM - 6:42PM
// TODO: took too long!!

//the best solution!
class Solution {	
public:
    int findComplement(int num) {
        int mask = num;
    	mask = mask | (mask >> 1);
    	mask = mask | (mask >> 2);
    	mask = mask | (mask >> 4);
    	mask = mask | (mask >> 8);
    	mask = mask | (mask >> 16);
    	return mask ^ num;
    }
};

// A more efficient solution
/*
class Solution {
public:
    int findComplement(int num) {
        
        int mask = ~0;
        
        if(num <= 0)
            return 1;
        
        while(num & mask)
        	mask = mask << 1;

        return ~mask & ~num;
    }
};
*/
/*
class Solution {
public:
    int findComplement(int num) {
        
        int result    = 0;
    	int mask	  = 0x1;
        int one_count = count_one(num);
    	int bit, i = 0;
    	
        if(one_count == 0)
            return 1;
        
    	while(one_count > 0){
    	    bit       = ((num & mask) != 0) ? 0 : 1;
    	    one_count = ((num & mask) != 0) ? one_count - 1 : one_count;
    	    bit       = bit << i;
    	    i         = i + 1;
    	    mask      = mask << 1;
    	    result    = result | bit;
    	}

        return result; 
    }
private:
	int count_one(int num){
		int count = 0;

		while(num > 0){
			num = (num - 1) & num;
			count++;
		}
		return count;
	}
};
*/
