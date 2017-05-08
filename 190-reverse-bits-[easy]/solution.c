// 12/13/16 8:32PM - 9:16PM

uint32_t reverseBits(uint32_t n) {
    
    uint32_t result = 0;
    
    int shift = 31;
    while(shift >= 0){
        int tmp = n & 1;
        tmp = tmp << shift;
        result = result | tmp;
        
        n = n >> 1;
        shift--;
    }
	return result;
}

// cleaner solution
uint32_t reverseBits(uint32_t n) {
    
    uint32_t result = 0;
    int i;

    for(i = 0; i < 32; i++){
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    return result;
}
//int n =  2147483648; ->expects 1;
 //int n = 43261596 ; -> expects 964176192 