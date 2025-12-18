// LeetCode (2461. Maximum Sum of Distinct Subarrays With Length K): 
// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k 


// This approach gives TLE 


#include<vector> 
#include<unordered_set> 
using namespace std; 


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size(); 
        long long maxSum = 0;

        for (int i=0; i < n-k+1; i++) {
            
            unordered_set<int> s; 
            long long sum = 0; 
            
            int j = i; 
            while (j < i+k) {
                sum += nums[j]; 
                s.insert(nums[j]); 
                j++; 
            }

            if (sum > maxSum && s.size() == k) maxSum = sum; 
        } 
            
        return maxSum;
    }
};


// T.C. = O(n*k) 
// S.C. = O(k) 

// Here, n = the total number of elements which are present inside the input vector named nums 