# 🎨 3 Ways of Defining Custom Comparators for Templates 


- Custom comparators can be defined: 
    1. for passing into functions (Ex: sort, stable_sort, etc.) 
    2. for passing into templates (Ex: priority_queue, etc.) 


## 1️⃣ Lambda (Requires Constructor Argument)
```cpp
auto cmp = [](int a, int b) { return a > b; };
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
```

## 2️⃣ Functor (Class with `operator()`)
```cpp
struct Compare {
    bool operator()(int a, int b) {
        return a > b;  // Min heap behavior
    }
};

priority_queue<int, vector<int>, Compare> pq;  // No constructor arg needed!
// Compare has default constructor
```

### 🔥 Functor for Custom Objects
```cpp
struct Person {
    string name;
    int age;
};

struct CompareAge {
    bool operator()(const Person& a, const Person& b) {
        return a.age > b.age;  // Min heap by age
    }
};

priority_queue<Person, vector<Person>, CompareAge> pq;
```

### 🎯 Functor with State (Requires Constructor Argument)
```cpp
struct CompareWithThreshold {
    int threshold;
    
    CompareWithThreshold(int t) : threshold(t) {}
    
    bool operator()(int a, int b) {
        return (a % threshold) > (b % threshold);
    }
};

CompareWithThreshold cmp(10);
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
```

## 3️⃣ Function Pointer
```cpp
bool compare(int a, int b) {
    return a > b;
}

priority_queue<int, vector<int>, decltype(&compare)> pq(compare);
```

---

# 📊 Comparator Comparison

| Type | Default Constructor | Need Constructor Arg | Use Case |
|------|-------------------|---------------------|----------|
| **`greater<T>`** | ✅ Yes | ❌ No | Simple types |
| **Lambda** | ❌ No | ✅ Yes | Quick inline logic |
| **Stateless Functor** | ✅ Yes | ❌ No | Reusable, readable |
| **Stateful Functor** | ❌ No | ✅ Yes | Needs configuration |
| **Function Pointer** | ⚠️ Special | ✅ Yes | Legacy code |

---

# 💭 Key Takeaways

## Comparators
- **Lambdas:** Need `decltype` + constructor arg (no default constructor)
- **Functors:** Clean, reusable; stateless ones don't need constructor arg
- **Type vs Object:** Template needs **type**, priority queue needs **object instance**

---

💡 **Pro Tip:** Use **functors** for reusable comparators, **lambdas** for one-off logic!