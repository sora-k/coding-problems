//started 2/20/17 8:13PM - 9:00PM (stuck)
/*

--> expect 10100010

a       1110101
b       0101101

xor = 1011000
and = 0100101, carry = 01001010

a  1011000
b 01001010

xor = 00010010
and = 01001000, carry = 010010000

a  00010010
b 010010000

xor = 10000010
and = 00010000, carry = 000100000

a  10000010
                    or
b 000100000
-----------
  result = 010100010
  and    = 000000000 ->terminating condition

=========================
(negative number)

1111
0001

xor 1110
and 0001, carry 00010

1110
00010

xor 01100
and 00010, carry 000100

001100
000100

xor 001000
and 000100, carry 0001000

0001000
0001000

xor 0000000
and 0001000, carry 00010000

00000000
00010000

xor 00000000
and 00000000, carry 0
*/
class Solution {
public:
   int getSum(int a, int b) {
       
       int result;
       int carry = 1;
       int exor;

       while(carry > 0 || carry < 0){
           carry = (a & b) << 1;
           exor  = (a ^ b);
           a     = exor;
           b     = carry ;
           
           result = carry | exor;
       }
       return result;
   }
};
/*
1
2
4
5
23423
1235
1211111
222
122341
9
999999
1
1
-1

*/
