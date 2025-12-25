# STL std::move() Function with Vectors in C++ - Ownership Transfer 


## 🔄 What is std::move()?

**std::move()** transfers ownership of resources from one object to another without copying data. It converts an [lvalue](https://github.com/aryan04-t/LeetCode-Jog/blob/master/00_Maths%20and%20Coding%20-%20Fundamentals%20and%20Tricks%20for%20Revision/41_What%20is%20lvalue%20and%20rvalue%20in%20C%2B%2B.md) into an [rvalue](https://github.com/aryan04-t/LeetCode-Jog/blob/master/00_Maths%20and%20Coding%20-%20Fundamentals%20and%20Tricks%20for%20Revision/41_What%20is%20lvalue%20and%20rvalue%20in%20C%2B%2B.md) reference, enabling move semantics.

**Key Point:** Move is NOT "copy by reference" - it's ownership transfer.

---

## 🤔 What does "converts lvalue to rvalue reference" mean?

### The Problem:
```cpp
vector<int> source = {1, 2, 3, 4, 5};  // source is an lvalue (has a name)
vector<int> dest = source;              // Copy happens! (expensive)
```

By default, when you use a **named variable** (lvalue), C++ assumes you still need it, so it **copies** the data.

### The Solution - std::move():
```cpp
vector<int> source = {1, 2, 3, 4, 5};  // source is an lvalue
vector<int> dest = std::move(source);  // Move happens! (cheap)
```

**What `std::move()` does:**
- Takes `source` (an lvalue with a name)
- Returns an **rvalue reference** (`vector<int>&&`) - this signals "temporary, can be stolen from"
- Tells the compiler: "I don't care about `source` anymore, treat it as temporary"
- This allows the compiler to **steal** `source`'s resources instead of copying them

**Important:** `source` itself is still an lvalue (still has memory address), but `std::move(source)` returns an rvalue reference that points to it, signaling it's okay to steal from.

---

## 🏠 Simple Analogy

**Without std::move():**
```
You: "Here's my house keys (source)"
Friend: "Thanks! Let me make a copy of these keys"
Result: Both have keys, expensive operation
```

**With std::move():**
```
You: "Here's my house keys, I'm moving away, just take them"
Friend: "Thanks!" *takes your keys*
Result: Friend has keys, you have nothing, but it was instant
```

**Bottom line:** `std::move()` is just a cast that says "I'm done with this object, you can take its guts."

---

## 📊 Example: Copy vs Move

### Copy by Value Assignment 
```cpp
vector<int> source = {1, 2, 3, 4, 5};
vector<int> dest = source;
```

**What happens:**
- `dest` allocates new memory
- All 5 elements are copied one by one
- Both `source` and `dest` own separate copies
- **Time Complexity:** O(n)

---

### Move Assignment (Ownership Transfer)
```cpp
vector<int> source = {1, 2, 3, 4, 5};
vector<int> dest = std::move(source);
```

**What happens:**

**Before:**
```
source.data → [1, 2, 3, 4, 5] (heap)
dest.data   → null
```

**After:**
```
dest.data   → [1, 2, 3, 4, 5] (heap)
source.data → null
```

✅ No copying  
✅ Pointers swapped  
✅ O(1) time complexity  
✅ `source` loses ownership (left in valid but unspecified state)

---

## ⚡ Why Move is O(1)

Containers like `vector` are essentially:
```cpp
struct vector {
    int* data;
    size_t size;
    size_t capacity;
};
```

Move assignment just swaps these pointer fields - no loop, no allocation, no element copying.