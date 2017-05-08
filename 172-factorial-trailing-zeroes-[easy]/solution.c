//started 12/10/16 5:17PM - 6:50PM
//		  12/11/16 1:04AM - 1:15AM
//				   6:00PM - 9:00PM

//TODO: revisit the problem!! took too long to understand
//		redo the problem quicker

int trailingZeroes(int n) {

	int count = 0;
	int divisor = 5;

	while(n > 0){
		count = count + n / 5;
		n /= 5;
	}

	return count;
} 
//efficient solution
// int trailingZeroes(int n) {

// 	int count = 0;
// 	int divisor = 5;

// 	while(n >= divisor){
// 		count = count + n / divisor;
// 		divisor *= 5;                       //--> overflow
// 	}

// 	return count;

// }

//solution works BUT time limit exceed!!! not efficient enough!
/*
int divisible_by_cnt(int num, int divisor){

	int count = 0;

	while(num > 0){
	    if(num % divisor == 0){
	        count++;
	        num /= divisor;
	    }else{
	        break;
	    }
	}
	return count;

}

int trailingZeroes(int n) {

	int count = 0;

	if(n == 0){
		return count;
	}else{
    	while(n % 5 != 0){
			count += divisible_by_cnt(n,5);
			n--;
		}
		while(n > 0){
			count += divisible_by_cnt(n,5);
		//	printf("%d ",n);
			n -= 5;
			count += divisible_by_cnt(n,5);
		//	printf("%d ",n);
			n -= 5;
			count += divisible_by_cnt(n,5);
		//	printf("%d ",n);
			n -= 5;
		}
	}

	return count;
}
*/
/*
1808548329
1000
100
0
1
2
3
4
5
6
7
8
9
33
40
44
1234
*/