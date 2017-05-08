//started 2/7/17 9:51PM - 10:35PM (stuck)
//                  2/8/17 7:00PM - 10:33PM

//TODO: took too long!
//                understand why dr(n) = n - 9*floor(n-9/9)
//
//                 Read the proofs-> https://en.wikipedia.org/wiki/Digital_root
//                                                    https://www.youtube.com/watch?v=LVfYevpPWZY
/*
Digital roots can be used as a sort of checksum, to check that a sum has been performed correctly. 
If it has, then the digital root of the sum of the given numbers will equal the digital root of the sum of the digital roots of the given numbers.
This check, which involves only single-digit calculations, can catch many errors in calculation.
*/

/*
       learned cool trick

       divisibility rule: 
               *a number is divisible by 3 if digital root of the number is 3, 6, or 9
               *a number is divisible by 9 if digital root of the number if 9
               a number is divisible by 6 if the number is divisible by 3 and 2
               a number is divisible by 4 if the last two digits is divisible by 4
*/


class Solution {
public:
   int addDigits(int num) {
       return num - 9 * ((num - 1) / 9);
   }
};