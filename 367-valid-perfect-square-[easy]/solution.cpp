// started 2/20/16 5:01PM - 7:00PM (? not sure)


class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num == 1){
            return true;
        }
        
        long l = 1;
        long r = num;

        while(l < r){

        	long middle = l + (r - l)/2;
        	long sqr    = middle * middle; 
        
        	if(sqr == num){
        		return true;
        	}
        	if(num < sqr){
        		r = middle;
        	}else{
        		l = middle + 1;
        	}

        }
        return false;

    }

};