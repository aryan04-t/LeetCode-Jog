```cpp
// Revise raw heap working mechanism dsa notes, and how to build heaps  

// And why greater<int>() makes a minHeap?? -> Like in custom sort we think of logic "when should a come before b?" and based on this logic the greater<int> does a descending sort and based on this logic we write custom comparator for custom sorts  

// But how are the comparisons working in heap that greater<int> is creating a min heap, like how to think of heap's inner swapping mechanism logic when writing a custom functor for heap's swapping logic??  
```



# 🗻 Heaps in C++

## 🎯 Default Behavior
- **C++ heaps are MAX heaps by default**
- Implemented using `priority_queue` from `<queue>` header

## 📦 Priority Queue Syntax

### Max Heap (Default)
```cpp
priority_queue<int> maxHeap;
```

### Min Heap
```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
```

**Template Parameters:**
1. **Data Type** - Type of elements (int, double, pair<int,int>, custom structs, etc.)
2. **Container Type** - Underlying container (usually `vector<T>`, also `deque<T>`)
3. **Comparator** - Comparison function (`less<T>` for max heap, `greater<T>` for min heap, custom comparators)

## 🏷️ Type Aliasing with `using`
```cpp
using MinHeap = priority_queue<int, vector<int>, greater<int>>;
using MaxHeap = priority_queue<int>;

MinHeap minH;  // Clean and readable!
MaxHeap maxH;
```

## 🔄 The -1 Trick
Multiply values by `-1` to convert max heap → min heap behavior:
```cpp
priority_queue<int> pq;
pq.push(-x);  // Insert negated
int val = -pq.top();  // Negate when retrieving
```

## ⚡ Time & Space Complexity

| Operation | Time Complexity |
|-----------|----------------|
| `push()` | O(log n) |
| `pop()` | O(log n) |
| `top()` | O(1) |
| `size()` | O(1) |
| `make_heap()` | **O(n)** ⭐ |

**Space:** O(n)

### 🤔 Why is `make_heap()` O(n)?
- **Building heap from array:** O(n) - uses bottom-up heapify
- **Inserting n elements one-by-one:** O(n log n) - each insert is O(log n)
- Bottom-up approach does less work at higher levels (most nodes are leaves)

## 🔧 Common Operations
```cpp
priority_queue<int> pq;

pq.push(10);           // Insert
int top = pq.top();    // Access max
pq.pop();              // Remove max
bool empty = pq.empty();
int sz = pq.size();
```

## 🎨 Custom Comparators
```cpp
// Min heap for pairs (by second value)
auto cmp = [](pair<int,int> a, pair<int,int> b) { 
    return a.second > b.second; 
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
```





# 🤔 Why Pass Comparator to Constructor?

## 🎯 Key Insight
**`decltype(cmp)` = TYPE, not the actual object!**
```cpp
auto cmp = [](int a, int b) { return a > b; };
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
//                                 ^^^^^^^^^^^^^  ^^^^
//                                 TYPE           OBJECT
```

### Template Parameters (Compile-Time)
- `decltype(cmp)` → Tells compiler the **type** to expect

### Constructor Argument (Runtime)
- `cmp` → Passes the **actual object** to use for comparisons
- Priority queue **stores a copy** and **calls it** during operations

## 💥 Without Constructor Argument
```cpp
auto cmp = [](int a, int b) { return a > b; };
priority_queue<int, vector<int>, decltype(cmp)> pq;  // ❌ ERROR!
// Lambdas have no default constructor!
```

## ✅ When Constructor NOT Needed
```cpp
priority_queue<int, vector<int>, greater<int>> pq;  // ✅ Works!
// greater<int> has default constructor
```



## 📚 Related
→ **My DSA Heap Notes**: [Link](https://github.com/aryan04-t/DSA-Notes/tree/master/Flow-12%20(Heaps))  
→ You can check out these notes for detailed heap data structure theory (heapify, heap sort, properties, proof of make_heap O(n) time complexity, etc.) 

---
💡 **Pro Tip:** For k-smallest problems use max heap, for k-largest use min heap!