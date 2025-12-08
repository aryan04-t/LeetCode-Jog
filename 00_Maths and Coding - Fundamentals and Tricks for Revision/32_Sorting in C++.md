# Sorting in C++ 

## 📚 What Does Sorting Mean?

**Sorting** is the process of arranging elements in a specific order based on a comparison criterion.

### 🔤 Types of Sorted Orders

#### 1. Ascending Order (Strictly Increasing)

Each element is **strictly less than** the next element. No duplicates in sequence.
```cpp
// Example: Ascending sorted array
{1, 2, 3, 4, 5}  ✅
{1, 1, 2, 3}     ❌ (has duplicate, not strictly ascending)

// Definition: arr[i] < arr[i+1] for all valid i
```

#### 2. Descending Order (Strictly Decreasing)

Each element is **strictly greater than** the next element. No duplicates in sequence.
```cpp
// Example: Descending sorted array
{5, 4, 3, 2, 1}  ✅
{5, 5, 3, 2}     ❌ (has duplicate, not strictly descending)

// Definition: arr[i] > arr[i+1] for all valid i
```

#### 3. Non-Decreasing Order (Ascending with duplicates allowed)

Each element is **less than or equal to** the next element. Duplicates allowed.
```cpp
// Example: Non-decreasing sorted array
{1, 2, 2, 3, 3, 3, 4}  ✅
{1, 1, 1, 1, 1}        ✅ (all same values is valid)
{1, 3, 2, 4}           ❌ (not sorted)

// Definition: arr[i] <= arr[i+1] for all valid i
// Most common sorting in practice
```

#### 4. Non-Increasing Order (Descending with duplicates allowed)

Each element is **greater than or equal to** the next element. Duplicates allowed.
```cpp
// Example: Non-increasing sorted array
{5, 4, 4, 3, 3, 3, 1}  ✅
{5, 5, 5, 5, 5}        ✅ (all same values is valid)
{5, 3, 4, 2}           ❌ (not sorted)

// Definition: arr[i] >= arr[i+1] for all valid i
```

### 📊 Quick Comparison Table

| Order Type | Symbol | Duplicates | Example |
|------------|--------|------------|---------|
| **Ascending** | `<` | ❌ Not allowed | `{1, 2, 3, 4, 5}` |
| **Descending** | `>` | ❌ Not allowed | `{5, 4, 3, 2, 1}` |
| **Non-Decreasing** | `<=` | ✅ Allowed | `{1, 2, 2, 3, 5}` |
| **Non-Increasing** | `>=` | ✅ Allowed | `{5, 3, 3, 2, 1}` |

### 💡 Important Note

In most programming contexts, when people say "ascending sort" or "descending sort," they usually mean **non-decreasing** or **non-increasing** order (duplicates allowed).
```cpp
// std::sort produces non-decreasing order by default
vector<int> nums = {3, 1, 2, 2, 1};
sort(nums.begin(), nums.end());
// Result: {1, 1, 2, 2, 3}  ← Non-decreasing (duplicates preserved)
```


## 🔐 What is Stable or Unstable Sort?

A sort is **stable** if it preserves the relative order of equal elements, and if the relative order of equal elements in not preserved then its called **unstable** sort.

`Stability of the sort depends on the nature of the algorithm.`


```cpp
struct Student {
    string name;
    int score;
};

vector<Student> students = {
    {"Alice", 90},
    {"Bob", 85},
    {"Charlie", 90}  // Same score as Alice
};

// Stable sort by score
stable_sort(students.begin(), students.end(), [](auto& a, auto& b) {
    return a.score < b.score;
});

// Result with stable_sort:
// Bob(85), Alice(90), Charlie(90)  ✅ Alice still before Charlie

// Result with std::sort:
// Bob(85), Charlie(90), Alice(90)  ❌ Order of Alice/Charlie may change
```

**Use `std::stable_sort` when you need stability** (slightly slower but preserves order of equal elements).



## 🔧 C++ Built-in Sort Details

**Function Name:** `std::sort` (from `<algorithm>` header)

**Algorithm:** **Introsort** (Introspective Sort) - This is a hybrid sort 

**This sort is unstable**

**Components:**
- 🚀 **QuickSort** - Fast average case O(n log n)
- 🛡️ **HeapSort** - Fallback when recursion depth gets too deep (prevents O(n²) worst case of quick sort)
- ⚡ **Insertion Sort** - For small subarrays (< 16 elements typically)

**Why Hybrid?** Combines the speed of QuickSort with the guaranteed O(n log n) worst-case performance of HeapSort.

### ⏱️ Time and Space Complexity

| Case | Time Complexity | Space Complexity |
|------|----------------|------------------|
| **Best** | O(n log n) | O(log n) |
| **Average** | O(n log n) | O(log n) |
| **Worst** | O(n log n) | O(log n) |

**Space:** O(log n) for recursion stack



## 🔒 C++ Stable Sort Details

**Function Name:** `std::stable_sort` (from `<algorithm>` header)

**Algorithm:** Hybrid of **Merge Sort** variants

**Components:**
- 🔀 **Merge Sort** - When enough memory is available
- 🎯 **In-place Merge Sort** - When memory is limited (falls back to avoid allocation failure)

**This sort is stable**

**Why Merge Sort?** Merge Sort is naturally stable and guarantees O(n log n) time complexity while preserving relative order of equal elements.

### ⏱️ Time and Space Complexity

| Case | Time Complexity | Space Complexity |
|------|----------------|------------------|
| **Best** | O(n log n) | O(n) |
| **Average** | O(n log n) | O(n) |
| **Worst** | O(n log n) | O(n) |

**Space:** O(n) for temporary merge buffer (or O(1) with in-place variant, but slower)

### 📊 Comparison: `sort` vs `stable_sort`

| Feature | `std::sort` | `std::stable_sort` |
|---------|-------------|-------------------|
| **Stability** | ❌ Not stable | ✅ Stable |
| **Speed** | Faster | Slightly slower |
| **Space** | O(log n) | O(n) |
| **Use When** | Order of equal elements doesn't matter | Need to preserve original order of equal elements |



## Sorting Algorithms Stability Comparison

| Sort Algorithm      | Stable? | Notes                                                |
|---------------------|---------|------------------------------------------------------|
| Bubble Sort         | Yes     | Adjacent swaps preserve relative order               |
| Selection Sort      | No      | Swaps non-adjacent elements                          |
| Insertion Sort      | Yes     | Inserts elements without disrupting equal elements   |
| Merge Sort          | Yes     | Merge operation can preserve order                   |
| Quick Sort          | No      | Partitioning swaps non-adjacent elements             |
| Heap Sort           | No      | Heap operations don't preserve relative order        |
| Intro Sort          | No      | Hybrid (quicksort + heapsort), inherits instability  |
| Tim Sort            | Yes     | Hybrid (merge + insertion), designed for stability   |
| Counting Sort       | Yes*    | When implemented properly                            |
| Radix Sort          | Yes*    | Depends on underlying stable sort (usually counting) |
| Bucket Sort         | Yes*    | If buckets sorted with stable algorithm              |
| Shell Sort          | No      | Gap-based comparisons break stability                |
| Cycle Sort          | No      | Minimizes writes, not stable                         |