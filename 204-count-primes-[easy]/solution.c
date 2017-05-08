//12/22/16 (paper planning, video learning) 8:00PM - 10:00PM
//12/23/16 (reading) 7:00AM - 9:30AM
//12/24/16 (reading) 8:00PM - 10:00PM
//12/25/16 (coding) 9:00PM - 10:10PM

//TODO: took too long!
//		 implement O(n*n^1/2) solution
//		 implement sieve_of_eratosthenes from scratch again
//	   	 Figure out runtine, why O(nlog(log(n)))--??
//		 Try to optimize the code without extra space?

void sieve_of_eratosthenes(bool *primeArr,int size){	//runtime O(size*loglog(size))
    
    if(size <= 0){
    	return;
    }
    for(int i = 0; i < size; i++){
    	primeArr[i] = true;
    }
    for(int i = 0; i * i < size; i++){
    	if(i == 0 || i == 1){
    		primeArr[i] = false;
    	}
    	else{
        	int inc = i;
        	for(int k = inc * i; k < size; inc++, k = i * inc){
        		primeArr[k] = false;
        	}
    	}
    }
}

int countPrimes(int n) {
    
    int result = 0;
    
    int size = n + 1;
    bool primeArr[size];
    sieve_of_eratosthenes(primeArr,size);
    
    for(int i = 0; i < n; i++){
        if(primeArr[i] == true){
            result++;
        } 
    }
    return result;
}