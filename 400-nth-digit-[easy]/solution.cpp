// started 2/28/17 10:14PM - 11:18PM (stuck)
// started 3/6/17   9:28PM - 11:06PM (stuck - timelimit exceed)

// TODO: took too long!!!!
// TODO: solution too complicated!!!
// study solution!
// study discretemath!!
class Solution {   
public:
   int findNthDigit(int input) {
            
      int result = 0;
 
      long prev_n, n = input;
      long group_digit_per_number = 1;
      long group_first_num        = 1;
      long group_multiple10       = 10;
      long group_digit_cnt        = ((group_multiple10 - 1) - group_first_num) + 1;
      
      if(n == 0) 
        return 0;
      
      prev_n  = n;
      n       = n - group_digit_cnt;
      
      //cout<<"n:";
     //cout<< n << " ";
      while(n > 0){         //calculate target digit count                O(logn)
          group_digit_per_number++;
          group_first_num  *= 10;
          group_multiple10 *= 10;
          
          group_digit_cnt  = ((group_multiple10 - 1) - group_first_num) + 1;
          group_digit_cnt *= group_digit_per_number;
          prev_n           = n;
          n                = n - group_digit_cnt;
              
              //cout<< n << " ";
      }
      //cout<<endl;
      
      //calculate the target number
      long target_digit = prev_n % group_digit_per_number;
      long offset       = (prev_n / group_digit_per_number == 0) ? prev_n : prev_n / group_digit_per_number;
           offset       = (target_digit == 1) ? offset + 1 : offset; // <-- quick fix
      long target_number= (group_first_num + offset) - 1;
      
      //calculate the target digit
      target_digit  = (target_digit == 0) ? group_digit_per_number : target_digit; //target_digit = 0 implies last digit of target_number
      long divisor  = group_multiple10 / 10;
      
//          cout<< "target_digit:" <<target_digit<<endl;
//          cout<< "prev_n: "<<prev_n<<endl;
//          cout<< "group_digit_per_number:" <<group_digit_per_number <<endl;
//          cout<< "offset:" <<offset <<endl;
//          cout<< "target_number: "<<target_number<<endl;
      
      while(0 < target_digit){        // O(n)
          result        = target_number / divisor;
          target_number = target_number % divisor;
          
          divisor /= 10;
          target_digit--;
      }
      
      return result;
   }
};

/*
10 / 10 = 1
12 % 10 = 2 , 12 / 10 = 1 
9  / 10 = 0
8 

1 / 10 = 0 , 1 % 10 = 1
2 / 10 = 0 , 2 % 10 = 2
3 / 10 = 0 , 3 % 10 = 3
4 / 10 = 0 , 4 % 10 = 4
5 / 10 = 0 , 5 % 10 = 5
.
.
.
10 / 10 = 1, 10 % 10 = 0
11 / 100 = 0, 11 % 100 = 0
.
.
.
40 / 100 = 0, 40 % 100 = 0 
*/
/*
class Solution {   //O(n) algorithm  (stuck - timelimit exceed)
public:
   int findNthDigit(int n) {
            
            int result = 0;
            int divisor = 1, tmp_divisor = 1;
            int tmp_num, i = 0, current_num = 0;

            while(i < n){
                    divisor         = (current_num / (divisor * 10) == 1 && current_num % (divisor * 10) == 0) ?
                                   divisor * 10 : divisor; 
                       tmp_num         = current_num;
                tmp_divisor = (current_num == 0) ? 0 : divisor;
                    current_num = current_num + 1;

                    while(0 < tmp_divisor && i < n){
                        result      = tmp_num / tmp_divisor; 
                            tmp_num     = tmp_num % tmp_divisor;
                            tmp_divisor = tmp_divisor / 10;
                            i           = i + 1;
                    }
            }
            return result;
   }
};
*/

/*
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
10
11
12
13
14
15
16
17
18
19
20
2147483646
1000000000
*/
