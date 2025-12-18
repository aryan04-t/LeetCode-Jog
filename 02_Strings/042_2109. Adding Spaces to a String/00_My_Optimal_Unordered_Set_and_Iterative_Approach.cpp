// LeetCode (2109. Adding Spaces to a String): 
// https://leetcode.com/problems/adding-spaces-to-a-string 


#include<vector> 
#include<unordered_set> 
#include<string> 
using namespace std; 


class Solution {
public:

    string addSpaces(string s, vector<int>& spaces) {
        
        unordered_set<int> spacesSet(spaces.begin(), spaces.end()); 
        
        int i = 0; 
        int n = s.length(); 

        string ans = ""; 

        while (i < n) { 
            if (spacesSet.find(i) != spacesSet.end()) ans += ' '; 
            ans += s[i]; 
            i++;
        }

        return ans; 
    }
}; 


// T.C. = O(m) + O(n) = O(2n) = O(n) 
// S.C. = O(m) + O(2n) = (s.c. of unordered_set + s.c. of ans string) = O(3n) = O(n) 

// Here, n = the length of input string named "s", and m = the total number of integers which are present inside the 1-D input vector named "spaces", in worst case m == n 