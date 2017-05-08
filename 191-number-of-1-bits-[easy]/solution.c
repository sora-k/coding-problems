// 12/14/16 (coding) 8:00AM - 8:20AM

// solution 1
/*
int hammingWeight(uint32_t n) {
    
    int count = 0;
    int i;
    
    for(i = 0; i < 32; i++){
        count = (n & 1 == 1) ? count + 1 : count;
        n = n >> 1;
    }
    return count;
}
*/
//solution 2
// flip least sig bit to zero and count, until n become zero
int hammingWeight(uint32_t n) {
    
    int count = 0;
    
    while(n > 0){
        count++;
        n = n & (n - 1);
    } 
   
    return count;
}
