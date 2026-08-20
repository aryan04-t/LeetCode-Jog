https://www.geeksforgeeks.org/problems/implement-lower-bound/1

https://www.geeksforgeeks.org/problems/implement-upper-bound/1 


give definitions of both functions 
define there implementations outcome from STL 
--> 23_Upper Bound and Lower_Bound in C++, Use of Binary Search

Also explain the overflow handling trick while calculating mid in binary search
 
```cpp
int mid = start + (end - start)/2;
```

# Also binary search at a 2-D Array 


https://chatgpt.com/c/6940e60b-10bc-8320-8a59-edb956abe161 

Making STL binary search lower_bound work on vector<pair<int, int>>, where I want to search on the basis of p.second value, writing a comparator for lower_bound following "strict weak ordering" rules 

-> Question reference where lower_bound needs a custom comparator to sort on pair<int, int>: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/ 