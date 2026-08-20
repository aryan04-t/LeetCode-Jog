# 🔍 `decltype` in C++

## 📖 Definition
**`decltype`** = "**decl**ared **type**" - deduces the type of an expression at compile-time

## 💡 Basic Usage
```cpp
int x = 5;
decltype(x) y = 10;  // y is type int

auto a = 3.14;
decltype(a) b = 2.71;  // b is type double

vector<int> vec;
decltype(vec) another_vec;  // another_vec is vector<int>
```

## 🆚 `decltype` vs `auto`

| Feature | `auto` | `decltype` |
|---------|--------|-----------|
| **Deduces from** | Initializer | Expression |
| **Usage** | Variable declaration | Type extraction |
| **Example** | `auto x = 5;` | `decltype(x) y;` |


---


# 🚀 `auto` Keyword in C++

## 📅 Introduction
- **Introduced:** C++11 (2011)
- **Purpose:** Automatic type deduction from initializer

## 🎯 Use Cases
```cpp
// Avoid typing long types
auto x = 5;  // int
auto pi = 3.14;  // double
auto name = "Alice";  // const char*

// Complex types made easy
auto it = vec.begin();  // vector<int>::iterator
auto lambda = [](int x) { return x * 2; };  // Lambda type

// Range-based loops
for (auto& elem : vec) { /* ... */ }

// Template return types
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}
```

## ⚠️ Rules
- **Must have initializer:** `auto x;` ❌ | `auto x = 5;` ✅
- **Strips references/const by default:** Use `auto&` or `const auto&` explicitly



# 💭 Key Takeaways

## `decltype`
- Gets type of expression at **compile-time**
- Essential for lambdas in templates (anonymous types)

## `auto`
- Introduced in **C++11**
- Automatic type deduction from initializer
- Simplifies complex type declarations