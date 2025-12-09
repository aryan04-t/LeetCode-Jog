# Custom Sorting in C++ 


## What is Custom Sort?

**Custom sort** is sorting elements using your own comparison logic instead of the default ordering.


## 🛠️ What is Needed to Write Custom Sort in C++

### Prerequisites

To write a custom sort in C++, you need:

1. **Container to sort** (vector, array, deque, etc.)
2. **Iterator pair** (begin and end iterators)
3. **Custom comparator function** (lambda, function pointer, or functor)
```cpp
#include <algorithm>  // For std::sort
#include <vector>

vector<int> nums = {5, 2, 8, 1, 9};

sort(nums.begin(), nums.end(), comparator);
//   ^beginning    ^end         ^your custom logic
```

## 🎯 What is a Custom Comparator?

A **custom comparator** is a function that defines how two elements should be ordered relative to each other.

**Signature:** Takes two elements and returns a boolean.
```cpp
bool comparator(Type a, Type b) {
    // return true if 'a' should come before 'b'
    // return false otherwise
}
```

## 📝 Ways to Write Custom Comparator

### 1. Lambda Function (Most Common)
```cpp
sort(nums.begin(), nums.end(), [](int a, int b) {
    return a < b;  // Ascending order
});
```

### 2. Regular Function
```cpp
bool myComparator(int a, int b) {
    return a < b;
}

sort(nums.begin(), nums.end(), myComparator);
```

### 3. Functor (Function Object)
```cpp
struct MyComparator {
    bool operator()(int a, int b) const {
        return a < b;
    }
};

sort(nums.begin(), nums.end(), MyComparator());
```

## 💡 Real-World Examples of Custom Sort

### Example 1: Sort by Absolute Value
```cpp
vector<int> nums = {-5, 3, -2, 8, -1};

sort(nums.begin(), nums.end(), [](int a, int b) {
    return abs(a) < abs(b);
});

// Result: {-1, -2, 3, -5, 8}
```

### Example 2: Sort Strings by Length
```cpp
vector<string> words = {"apple", "pie", "banana", "kiwi"};

sort(words.begin(), words.end(), [](string& a, string& b) {
    return a.length() < b.length();
});

// Result: {"pie", "kiwi", "apple", "banana"}
```

## 🎯 Key Takeaway

**Custom comparator = Your definition of "which element comes first"**

The comparator answers one question: **"When should `a` come before `b`?"**

- - - 


## 🔥 How Custom Comparator Really Works in Sorting

**Important:** Sorting algorithms DO NOT use the comparator to decide exact swap rules on every comparison.

**What Actually Happens:**
- Algorithms use the comparator to **navigate the data structure** (partitions, merges, pivots, heaps)
- Swaps happen as a **result of those navigations**, not directly from comparator calls
- The comparator answers: "What is the relative ordering between a and b?"

**Example with QuickSort:**
```cpp
// Role of custom comparator comp() in Quick Sort 
1. Pick a pivot
2. Use comp() to partition: elements where comp(elem, pivot) = true go left
3. Recursively sort left and right partitions
4. Swaps happen during partitioning, not from direct comp() results
```

**Why This Matters:**
- Your comparator defines **ordering relationships**, not swap logic
- The algorithm interprets these relationships to organize data efficiently
- This is why strict weak ordering is critical—algorithms rely on consistent relationships


## 🎯 Correct Intuition for Writing Custom Sort

**Think:** "When should `a` come **before** `b` in the final sorted order?"

✅ Return `true` → Yes, `a` should come before `b`  
✅ Return `false` → No, `a` shouldn't come before `b` 
```cpp
// Example: Sort by absolute value
sort(nums.begin(), nums.end(), [](int a, int b) {
    return abs(a) < abs(b);  // "a before b if |a| is smaller"
});
```


## 📏 Rules for Writing Custom Comparator

In C++, when we write a custom comparator, the custom comparator's logic should follow a mathematical property called `strict weak ordering` - and this property defines the rules for writing custom comparator.


### ❓ What is "Strict Weak Ordering" 

`Strict weak ordering` is a mathematical property (or requirement/constraint). It is basically a binary relation - typically represented by a comparison function or operator (like operator <), that defines a specific type of ordering between elements.

Sorting algorithms rely on "strict weak ordering" rules. Breaking them causes incorrect or unstable behavior.


### ✅ Meaning of "Strict Weak Ordering"

**Strict** = `a < a` is always false 

**Weak** = different objects can tie based on comparison criteria

**Example:**
- `Person{"Alice", 25}` vs `Person{"Bob", 25}` sorted by age
- `!(Alice < Bob) && !(Bob < Alice)` = they tie
- They're **equivalent** (tie in ordering) but not **equal** (different objects)
- The ordering is "weak" because it deliberately ignores differences irrelevant to the comparison (names don't matter, only age does)

**Ordering** = defines how to arrange/rank elements (transitivity: if `a < b` and `b < c`, then `a < c`)


## ✅ The Three Golden Rules of "Strict Weak Ordering" Property 

#### These rules should be followed when writing custom comparators 

### 1️⃣ Irreflexivity: `comp(x, x)` must be `false`

**Rule:** An element cannot be less than itself.
```cpp
// ❌ BAD: Returns true when a == b
sort(nums.begin(), nums.end(), [](int a, int b) {
    return a <= b;  // Returns true when a == b
});

// ✅ GOOD: Returns false when a == b
sort(nums.begin(), nums.end(), [](int a, int b) {
    return a < b;  // Returns false when a == b
});
```

**If violated:** Infinite loops, crashes, undefined behavior.

**Example:** With `{5, 5, 5}` and `comp(5, 5) = true`, the algorithm thinks 5 should come before itself, causing it to swap indefinitely.

### 2️⃣ Asymmetry: If `comp(a, b)` is true, then `comp(b, a)` must be false

**Rule:** If a comes before b, then b cannot come before a.
```cpp
// ❌ BAD: Both can be true
sort(nums.begin(), nums.end(), [](int a, int b) {
    return (a % 2 == 0) && (b % 2 == 0);  // comp(4,6) and comp(6,4) both true
});
```

**If violated:** Contradictory ordering decisions, unpredictable results.

**Example:** With `{4, 6}`, if both `comp(4, 6)` and `comp(6, 4)` are true, the algorithm can't decide which comes first.

**For equal items:**
```cpp
comp(a, b) = true
comp(b, a) = true
```

This makes the sort think:
- `a < b` AND also `b < a`
- This is logically impossible and destroys sort correctness
- Elements keep swapping back and forth indefinitely

### 3️⃣ Transitivity: If `comp(a, b)` and `comp(b, c)` are true, then `comp(a, c)` must be true

**Rule:** If a < b and b < c, then a < c must hold.
```cpp
// ❌ BAD: Non-transitive comparison
sort(nums.begin(), nums.end(), [](int a, int b) {
    return (a - b) % 3 == 1;  // Not transitive
});
```

**If violated:** Inconsistent element ordering, incorrect sort results.

**Example:** With `{1, 2, 3}`, if `comp(1,2)` and `comp(2,3)` are true but `comp(1,3)` is false, the algorithm gets contradictory information about ordering.

### ⚠️ Common Mistakes

| Wrong ❌ | Right ✅ | Why |
|---------|---------|-----|
| `a <= b` | `a < b` | `<=` returns true when equal (violates irreflexivity) |
| `a >= b` | `a > b` | `>=` returns true when equal (violates irreflexivity) |
| `rand() % 2` | Deterministic logic | Random comparisons violate transitivity |


## ❓ Why `a == b` Should Always Return `false`

**Reason:** Satisfies **Irreflexivity** requirement and prevents unnecessary swaps.

When `a == b` in non-decreasing sort, the comparator is essentially asking: "Is a less than itself?" The answer must be `false`.
```cpp
// When a == b, these are equivalent:
comp(a, b)  // Is a less than b?
comp(a, a)  // Is a less than itself? → Must be FALSE
```

**Key Insight:** For equal elements, returning `false` ensures:
1. No logical contradiction (a cannot be less than itself)
2. Algorithm gets consistent ordering information
3. Equal elements don't create conflicting navigation signals

**Remember:** The actual algorithm uses the comparator to navigate data structures, not to directly trigger swaps. Returning `false` for equal elements maintains consistent ordering relationships that algorithms rely on.


## ❓ What defines Stability of a Sort?? 

`Stability of a sort is defined by the Comparator or the Algorithm??` 

The stability guarantee comes from the algorithm, not from the comparator. 

stable_sort and sort, both sort's custom comparators require "strict weak ordering" to be followed when you define the custom comparators. 


## 🔼🔽 Writing Ascending and Descending Comparators

### 🔼 Ascending Order (Smaller values first)
```cpp
// Simple ascending
sort(nums.begin(), nums.end(), [](int a, int b) {
    return a < b;  // "a before b if a is smaller"
});
```

### 🔽 Descending Order (Larger values first)
```cpp
// Simple descending
sort(nums.begin(), nums.end(), [](int a, int b) {
    return a > b;  // "a before b if a is larger"
});
```


## Quick Summary Card: 

```
✅ Always use: < or >
❌ Never use: <= or >=
🎯 Custom comparator = Your definition of "which element comes first"
💡 Think: "When should a come BEFORE b in final order?"
🔑 When a == b, always return false (automatically handled by < and >)
🔥 Comparator defines ordering relationships, not direct swap logic
🔥 Algorithms navigate data structures using these relationships
```