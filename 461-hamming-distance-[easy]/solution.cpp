//461. Hamming Distance

// started 4/11/17 8:52PM - 9:19PM

class Solution {
public:
    int hammingDistance(int x, int y) {
     	
     	int result_count = 0;
     	int xor_x_y 	 = x ^ y;

     	while(xor_x_y > 0){
     		result_count = result_count + 1;
     		xor_x_y 	 = (xor_x_y & (xor_x_y - 1));
     	}
     	return result_count;
    }
};