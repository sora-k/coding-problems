```
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.
```

### Attempt 1 (9/16/16 - 9/18/16)
Run time of O(n^2)
```
1. Merge-sort the array into a new array. 
2. Iterate through the sorted array. - 
     At the current element, binary-search the other element that make up the target. (e.g. current = 2, difference = 7, find 7) - (log(n))
     Find the indexes within the origial array. - O(2n)
```
####Performance:
39 ms, beating 92.04% of c submissions.
### Future attempt
Use Hash for finding the original index. Improve overall runtime to O(n). 
