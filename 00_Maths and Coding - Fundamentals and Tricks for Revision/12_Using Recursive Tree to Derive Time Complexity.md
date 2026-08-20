## 🔹 Using Recursive Tree to Derive Time Complexity

### Example Problem
> Generate all permutations of a string of length `n` using **only 26 lowercase characters**.  
> We use a recursive function where **each call iterates over 26 letters** and recursively builds the string.

### Recursive Function Skeleton
```cpp
#include <iostream>
#include <string>
using namespace std;

void buildPermutations(string& curr, int n) {
    if (curr.size() == n) {
        // Base case: a full permutation is formed
        cout << curr << endl;
        return;
    }

    for (char c = 'a'; c <= 'z'; c++) {  // 26 branches per level
        curr.push_back(c);
        buildPermutations(curr, n);
        curr.pop_back();
    }
}

int main() {
    int n = 3;  // Example length
    string curr = "";
    buildPermutations(curr, n);
    return 0;
}
```

---

### Visualizing the Recursive Tree

- **Level 0:** root call → 1 function call  
- **Level 1:** each root call spawns **26 recursive calls**  
- **Level 2:** each of those 26 calls spawns **26 more calls**, giving `26^2` calls  
- **Level i:** `26^i` function calls  
- **Depth of tree:** `n` (length of string)  

---

### Sum of Function Calls

The total number of function calls = sum of nodes in the tree:

> 1 + 26 + 26^2 + 26^3 + ... + 26^n

This is a geometric progression (GP) with ratio `r = 26`. 
GP sum formula for the first n terms = (a*((r^n) - 1))/(r-1) 

Using GP sum formula to get sum from `i = 0` to `n`:

`Total calls = ((26^(n+1)) - 1) / (26 - 1) = ((26^(n+1)) - 1) / 25`

Dropping constant factors gives the asymptotic form:

`Total calls = Θ(26^n)`  (and thus Time Complexity = `O(26^n)`)

---

### Worst-Case Time Complexity

- **Time per function call:** `O(1)` (pushing/popping a character, ignoring output)  
- **Number of calls:** `≈ 26^n`  

> Worst-case Time Complexity = O(26^n) 

- **Space Complexity:** `O(n)` for the recursion stack (depth = n)

---

### Key Insight
By **visualizing each recursive call as a node in a tree** and summing all nodes per level, we can **derive the exponential growth** and confirm the **time complexity**.