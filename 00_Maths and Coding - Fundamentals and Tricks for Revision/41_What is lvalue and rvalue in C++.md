# What is lvalue and rvalue in C++: 

## 📍 What is an lvalue?

An **lvalue** (locator value) is an expression that:
- Has a **name**
- Has a **stable memory address**
- Can appear on the **left side** of an assignment
- Persists beyond a single expression

**Example:**
```cpp
vector<int> v;  // v is an lvalue
int x = 10;     // x is an lvalue
```

You can take the address: `&v`, `&x` ✅

---

## ⚡ What is an rvalue?

An **rvalue** (right value) is an expression that:
- Is **temporary**
- Usually has **no name**
- **Cannot** be assigned to
- Exists only during expression evaluation

**Example:**
```cpp
int y = x + 5;  // (x + 5) is an rvalue - temporary result
```

You cannot take the address: `&(x + 5)` ❌

---

## 🔑 Quick Test
```cpp
int a = 10;      // a is lvalue, 10 is rvalue
int b = a;       // both a and b are lvalues
int c = a + b;   // c is lvalue, (a + b) is rvalue

a = 20;          // ✅ OK - lvalue on left
10 = a;          // ❌ ERROR - cannot assign to rvalue
```

**Memory Rule:**  
If you can take its address with `&`, it's an lvalue. If not, it's an rvalue.