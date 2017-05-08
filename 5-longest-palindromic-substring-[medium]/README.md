```
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
```

### Attempt (10/22/16)
Run time of O(N^3) - where N is the length of string.
```
Setup steps:
1. (a) count number of each char occurrences in the string           -O(N)          
   (b) keep count of size of the string
   (c) kepp count of number of repeated char (e.g. "aabbcc" - 3 repeated chars)
   (d) and map each repeated char to repeatedCharInds array.
2. Init arrays for each repeated chars.   -O(N)
   Store each repeated char indices into their respective array (e.g. "abcaa" - array of indices for repeated char a = [0,3,4] ). 

Solution step:
3. Traverse through the arrays.(in the code the arrays are pointed to by repeatedCharInds pointer):  ~O(N^3)                                          NOTE:(1) O(N/2), max number of repeated chars
   4. Traverse through...combination of pairs...of repeated chars inds array ith (e.g. "abaca" - pair indices for a (0,2), (0,4), (2,4)):                  (2) ~O(N^2) <= O(N!/2!(N-2)!), max number of pairs e.g. only one repeated char
      5. Check if a pair of indices result in a greater lenght than the current largest palindromic string length.                                         (3) the greater the number of repeated chars, the smaller the number of pairs. e.g. (aaaa) 1 repeated char and 3 + 2 + 1 pairs.
      6. If it is, check whether the substring, where the end indices are the pair, is palindromic.                                                        (4) O(N/2), checking if a pair is palindromic.    
      7. Update current largest length and the start/end index of that substring.
8. Create substring at the start and end indice of the largest palindromic sub-string.
   (a) if nothing was found, return the first character of the string.
```
#### Performance:
 233 ms, beating 1% of c submissions - Really inefficient!
### Note for Future attempts
Optimize the current code to be closer to O(n). Note: also take into account cache misses when reading from array - the current implementation encourages cache misses! 
