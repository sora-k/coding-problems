```
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

1.
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
2.
    Input: [0] + [5,6,4]
    Output: [5,6,4]
3.  
    Input: [5,6,4] + [1,2,3,4]
    Output: [6,8,7,4]
4.  
    Input: [] + []
    Output: []
5.
    Input: [5,6,4] + [1,2,3]
    Output: [6,8,7]
6.  
    Input: [1,9,9,9,9,9,9,9,9,9] + [9]
    Output: [0,0,0,0,0,0,0,0,0,0,1]
7.
    Input: [9,8] + [1]
    Output: [0,9]
    
```

### Attempt 1 (9/23/16)
Run time of O(m) if m > n
otherwise   O(n)
where n is the number of elements in l1 and m is the number of elements in l2.
```
1. Traverse through both lists until pointer to l1 is NULL. 
    2. Add both number from current node of l1 and from current node of l2.
    3. Update the added number with carry value. Calculate a new carry value. Update the added value if greater than 9.
    3. Create a new node with the added value. Update the output list with the new node.
    4. Update both lists' pointers to point to the next element of the respective list.
5. Include any left over nodes within l2 list.
6. Create a new node for none zero carry.
7. Return the output list.
```
#### Performance:
19 ms, beating 20.63% of c submissions
### Note for Future attempts
Optimize the current code.
