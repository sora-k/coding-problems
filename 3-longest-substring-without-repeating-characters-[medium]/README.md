```
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

### Attempt 1 (10/2/16)
Run time of O(n^2)
```
1. Traverse through each characters within a given string. 
    2. From the current character,
       Traverse down the string until a repeat element is found or at the end of the string.
    3. Update current max length.
```
#### Performance:
19 ms, beating 32.17% of c submissions
### Note for Future attempts
Optimize the current code to be O(n).
