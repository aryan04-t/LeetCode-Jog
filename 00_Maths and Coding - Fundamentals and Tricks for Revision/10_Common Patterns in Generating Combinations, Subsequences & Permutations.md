# 🚀 Common Patterns in Generating Combinations, Subsequences & Permutations

Below are some **foundational algorithmic patterns** for generating subarrays, subsequences, and permutations — along with their **time complexities** and **example implementations**. These form the backbone of many combinatorial and backtracking problems.

---

## 1. 🔁 Building All **Subarrays / Substrings**
**Technique:** Two nested loops  
**Time Complexity:** `O(n²)`  
**Reasoning:** Each element can be the start of a subarray, and you iterate to all possible ends.

### ✅ Example (Subarrays)
```cpp
#include <iostream>
#include <vector>
using namespace std;

void printAllSubarrays(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = i; k <= j; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    printAllSubarrays(arr);
    return 0;
}
```

---

## 2. 🔂 Building All **Subsequences**
**Technique:** Recursion with “take / not take” choices  
**Time Complexity:** `O(2ⁿ)`  
**Reasoning:** Each element has 2 choices → included or excluded.

### ✅ Example (Subsequences)
```cpp
#include <iostream>
#include <vector>
using namespace std;

void generateSubsequences(vector<int>& arr, int idx, vector<int>& curr) {
    if (idx == arr.size()) {
        for (int x : curr) cout << x << " ";
        cout << endl;
        return;
    }

    // Take the current element
    curr.push_back(arr[idx]);
    generateSubsequences(arr, idx + 1, curr);
    curr.pop_back();

    // Not take the current element
    generateSubsequences(arr, idx + 1, curr);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> curr;
    generateSubsequences(arr, 0, curr);
    return 0;
}
```


---

## 3. 🔁 Recursion + Loop Inside → **All Permutations**
**Technique:** Recursive + Iterative swapping (Backtracking)  
**Time Complexity:** `O(n!)` (can reach `nⁿ` without pruning)  
**Reasoning:** For each index, you choose every possible remaining element.

### ✅ Example (Permutations)
```cpp
#include <iostream>
#include <vector>
using namespace std;

void generatePermutations(vector<int>& arr, int start) {
    if (start == arr.size()) {
        for (int x : arr) cout << x << " ";
        cout << endl;
        return;
    }

    for (int i = start; i < arr.size(); i++) {
        swap(arr[start], arr[i]);
        generatePermutations(arr, start + 1);
        swap(arr[start], arr[i]); // backtrack
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    generatePermutations(arr, 0);
    return 0;
}
```

---


## 4. ⚡ **Backtracking with Constraints**

### 🧠 Description
Used in problems like **N-Queens**, **Sudoku Solver**, **Combination Sum**, **Rat in a Maze**, etc.  
It builds solutions incrementally but **abandons branches early** when they violate constraints.

**Time Complexity:** Between `O(2ⁿ)` and `O(n!)` — highly input-dependent.

### ✅ Example (N-Queens)
```cpp
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;

    return true;
}

void solveNQueens(int row, int n, vector<string>& board) {
    if (row == n) {
        for (auto& r : board) cout << r << endl;
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueens(row + 1, n, board);
            board[row][col] = '.'; // backtrack
        }
    }
}

int main() {
    int n = 4;
    vector<string> board(n, string(n, '.'));
    solveNQueens(0, n, board);
    return 0;
}
```

---

## 5. 🎯 Generating Fixed-Length **Combinations (n Choose k)**

### 🧩 Concept
Unlike subsequences (which explore all `2ⁿ` subsets) or permutations (which care about order),  
**combinations** generate subsets of a **fixed size k**, and **order does not matter**.

You typically use a **recursive + iterative** approach — a mix of “take/not-take” recursion and a loop that progresses through remaining elements.

**Time Complexity:** `O(C(n, k))`  
**Technique:** Recursion with loop  
**Category:** Between subsequences and backtracking

---

### 💡 Example Problem Statement
> **Problem:**  
> Given integers `n` and `k`, return all possible combinations of numbers from `1` to `n` taken `k` at a time.  
> 
> **Example:**  
> Input: `n = 4, k = 2`  
> Output:  
> ```
> [1, 2]
> [1, 3]
> [1, 4]
> [2, 3]
> [2, 4]
> [3, 4]
> ```

---

### ✅ Example (Combinations)
```cpp
#include <iostream>
#include <vector>
using namespace std;

void generateCombinations(int n, int k, int start, vector<int>& curr) {
    if (curr.size() == k) {
        for (int x : curr) cout << x << " ";
        cout << endl;
        return;
    }

    for (int i = start; i <= n; i++) {
        curr.push_back(i);
        generateCombinations(n, k, i + 1, curr);
        curr.pop_back();
    }
}

int main() {
    int n = 4, k = 2;
    vector<int> curr;
    generateCombinations(n, k, 1, curr);
    return 0;
}
```

---

### 🧠 Common Use Cases
- Generating all **teams or groups** of size `k`
- Problems like **Combination Sum**, **Letter Combinations of a Phone Number**
- Used in **probability** and **binomial coefficient** calculations

---

## ✅ Summary Table

| Pattern Type | Example Problem | Technique | Time Complexity | Typical Use |
|---------------|----------------|------------|------------------|--------------|
| Subarrays / Substrings | Print all subarrays | 2 nested loops | O(n²) | Sliding windows, ranges |
| Subsequences | Power set | Recursion (take/not-take) | O(2ⁿ) | Subset sums, combinations |
| Permutations | String permutations | Recursive + loop (swap) | O(n!) | Rearrangements, orderings |
| Backtracking | N-Queens, Sudoku | Recursion + pruning | Between 2ⁿ–n! | Constraint-based search |
| Combinations (n choose k) | Generate k-size groups | Recursive + loop | O(C(n, k)) | Teams/groups, combination sum, probability |

