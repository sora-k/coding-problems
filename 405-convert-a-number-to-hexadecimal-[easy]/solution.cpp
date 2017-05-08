// started 3/13/17            11:00PM - 11:40PM
//         3/14/17             9:00AM - 10:00AM
 
class Solution {  // reasonable solution,
                  // the key was using unsinged int so that right shift is zero filled
                  // also concatination always create new string, unless specified as string builder implementation - don't worry about that!
public:
    string toHex(int num) {
                               
      string result   = "";
    
      char hex_char[] = {'0','1','2','3','4','5',
                         '6','7','8','9','a','b',
                         'c','d','e','f'
                        };

      unsigned int  num_ = num;  //using unsigned -> right shift is zero-filled
     
      if(num_ == 0)
          return "0";
     
      int ind;
      while(num_ != 0){
          ind    = num_ & 0x0000000F;
          result = hex_char[ind] + result;
          num_   = num_ >> 4;
      }
      return result;
    }
};
 
//TODO: took too long!
/*
class Solution {
public:
    string toHex(int num) {
                               
        string result   = "";
        int reverse_num = 0;
        char hex_char[] = {'0','1','2','3','4','5',
                           '6','7','8','9','a','b',
                           'c','d','e','f'
                          };
       
        unsigned int digit_isolater = 0xF0000000;   //zero-filled when shift right
        unsigned int curr_digit     = num & digit_isolater;
        int digit_ind               = 7;
       
        if(num == 0)
            return "0";
       
        while(curr_digit == 0){           //locate msb digit
               digit_isolater = digit_isolater >> 4;
               digit_ind--;
               curr_digit     = num & digit_isolater;
        }
        while(digit_isolater != 0){//generate hex string
               curr_digit     = num & digit_isolater;
   
               for(int i = 0; i < digit_ind; ++i)
                   curr_digit = curr_digit >> 4;
    
               digit_ind--;
               digit_isolater = digit_isolater >> 4;
                                result                       = result + hex_char[curr_digit];
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
26
-1
2147483647
*/