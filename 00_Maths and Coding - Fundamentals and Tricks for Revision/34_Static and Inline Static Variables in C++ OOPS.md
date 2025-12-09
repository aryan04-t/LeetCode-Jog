# Static Variables in C++

## What are Static Variables?

**Static variables** are variables that belong to the class itself rather than to individual objects. They are shared among all instances of the class and exist for the entire lifetime of the program.

**Non-static variables** (instance variables) are unique to each object - every object gets its own copy.

## Key Differences
```cpp
class Example {
public:
    static int staticVar;    // Shared by all objects
    int nonStaticVar;        // Each object has its own copy
};

// Usage:
Example obj1, obj2;
obj1.nonStaticVar = 10;      // Only affects obj1
obj2.nonStaticVar = 20;      // Only affects obj2

Example::staticVar = 5;      // Affects all objects
```

## The Definition Problem (Why You Get Errors)

When you declare a static member variable in a class, you're only **declaring** it, not **defining** it. The compiler needs a definition to allocate memory for it.

### Without `inline` - The Traditional Way:
```cpp
// In header file (.h)
class Solution {
public:
    static vector<int> vec;  // Declaration only
};

// In source file (.cpp) - REQUIRED
vector<int> Solution::vec;   // Definition - allocates memory
```

**Why this is needed:** The linker needs exactly ONE definition across all translation units. Without this external definition, you get a linker error: "undefined reference to Solution::vec"

## The `inline` Keyword Solution (C++ 17+)

The `inline` keyword allows you to define the static variable directly in the class:
```cpp
class Solution {
public:
    inline static vector<int> vec;  // Declaration AND definition
    // OR
    static inline vector<int> vec;  // Same thing, order doesn't matter
};

// No need for Solution::vec outside the class!
```

### What `inline` Does:

1. **Combines declaration and definition** - tells the compiler to define the variable right there
2. **Allows multiple definitions** - the linker merges all identical definitions into one
3. **Eliminates the need for separate definition** - no need for `Solution::vec;` outside the class

## What Happens Without `inline`?

Without `inline`, if you don't provide the external definition (`Solution::vec;`), you get:

- **Compile error** (in some cases): "static member 'vec' declared but not defined"
- **Linker error** (more common): "undefined reference to 'Solution::vec'"

The program compiles but fails at the linking stage because the memory was never allocated.

## How to Access Static Variables
```cpp
class Solution {
public:
    inline static vector<int> vec;
    
    void addValue(int val) {
        vec.push_back(val);  // Access inside class directly
    }
};

int main() {
    // Access using class name
    Solution::vec.push_back(10);
    
    // Access through object (works but not recommended)
    Solution obj;
    obj.vec.push_back(20);
    
    // All access the SAME variable
    cout << Solution::vec.size();  // Outputs: 2
}
```

## Complete Example
```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // With inline - no external definition needed
    inline static vector<int> vec;
    
    // Can also initialize inline static variables
    inline static int count = 0;
    
    void process(int val) {
        vec.push_back(val);
        count++;
    }
};

int main() {
    Solution s1, s2;
    
    s1.process(10);
    s2.process(20);
    
    // Both objects share the same static variables
    cout << "Vector size: " << Solution::vec.size() << endl;     // 2
    cout << "Count: " << Solution::count << endl;                 // 2
    
    return 0;
}
```

## Summary Table

| Aspect | Without `inline` | With `inline` |
|--------|-----------------|---------------|
| Declaration in class | `static vector<int> vec;` | `inline static vector<int> vec;` |
| External definition | **Required:** `vector<int> Solution::vec;` | **Not needed** |
| C++ Version | All versions | C++17+ |
| Memory allocation | At external definition | At class declaration |
| Error if definition missing | Linker error | No error |


## Best Practice

**Use `inline static` for C++17 and later** - it's cleaner and less error-prone. Only use the traditional approach if you need to support older C++ standards.


## LeetCode Example Where Static Variable was Used: 

3766. Minimum Operations to Make Binary Palindrome: [My Code](https://github.com/aryan04-t/LeetCode-Sprint/blob/master/3766.%20Minimum%20Operations%20to%20Make%20Binary%20Palindrome/01_Optimal_Precomputation_And_Binary_Search_Approach.cpp) 