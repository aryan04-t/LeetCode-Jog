# 🌳 Visualizing Time Complexity of Branching Recursion

Branching recursion is a key concept to estimate **time and space complexity** based on how many recursive calls happen at each level. Below is a structured observation of common branching patterns in recursion.

---

## 1. 🔹 1-Branch Recursion
- **Time Complexity:** `O(n)`  
- **Space Complexity:** `O(n)` (depth of recursion stack)  
- **Use Cases:** Traversing **linear data structures** like arrays, linked lists, stacks, strings.  
- **Note:** Here `n` = length of the data structure.  

---

## 2. 🔹 2-Branch Recursion
- **Time Complexity:** `O(2^h)` or `O(n)` where `h` = depth of recursion stack, `n` = total nodes  
- **Space Complexity:** `O(h)`  
- **Use Cases:** Traversing **binary trees** (normal trees or BSTs) using DFS.  
- **Note:** Even binary trees are a type of graph. Each node can branch into 2 recursive calls.  

---

## 3. 🔹 4-Branch Recursion
- **Time Complexity:** `O(4^h)`  
- **Space Complexity:** `O(h)`  
- **Use Cases:** Traversing a **2-D array** in all 4 directions (up, down, left, right) or **graph traversal**.  
- **Note:** Each position may recursively explore 4 possible directions.

---

## 4. 🔹 8-Branch Recursion
- **Time Complexity:** `O(8^h)`  
- **Space Complexity:** `O(h)`  
- **Use Cases:** Traversing a **2-D array or graph** including **diagonal moves**.  
- **Note:** All 8 directions (4 cardinal + 4 diagonal) are explored.

---

## 5. 🔹 26-Branch Recursion
- **Time Complexity:** `O(26^n)`  
- **Space Complexity:** `O(n)`  
- **Use Cases:**  
  - Generating **permutations of a string** with 26 lowercase letters  
  - Traversing a **Trie**  
- **Note:** Each character in the alphabet can branch recursively.

---

## 🧠 General Principle

> When recursion happens, the **number of recursive calls made from inside** the function roughly defines the **branching factor**.  
> 
> So, in general:  
> Time Complexity = O(((number of recursive calls in the function body)^(depth of recursion)) * (work done per node))
> 
> But **base cases**, **branch pruning**, and **overlapping subproblems** can reduce the actual time complexity drastically.

Above formula is only for giving context of **worst-case time complexities** of recursion in the case of **complete recursive trees** with no pruning, no visited tracking, and no overlapping subproblem optimizations. Each recursive function's body is assumed to have `O(1)` time complexity itself — this formula is just to give a **generalized idea of recursion growth based on number of branches**.

> For sure the base case is there for this formula. It doesn't fit the case when "number of recursive calls in function body" = 1, because 1^n = 1.  
> This formula is only applicable when "number of recursive calls in function body" ≥ 2.  
> For the case when "number of recursive calls in function body" = 1 && "depth of recursion" = n, the time complexity remains `O(n)` in this base case.