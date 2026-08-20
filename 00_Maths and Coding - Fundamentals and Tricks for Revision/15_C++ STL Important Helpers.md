# GO through Docs of C++ for knowning STL helpers, but they can be vast and sometimes verbose, so these are my short notes for revision - I will mention here STL helpers which I have used to make things easy: 

For sure refer C++ STL docs and go through all functions and member functions for sure (And always attempt questions with brute implementations and stl functions both) 


// Define headers of each, return type, parameters meaning, list the use case, and implementation under the hood, edge-cases and using ideas - also mention time and space complexities 

// Group these functions by headers 

// min_element
// max_element
// binary_search
// upper_bound

```js
// upper_bound, way of finding index

vector<int>::iterator it = upper_bound(arr.begin(), arr.end(), 3);

// Get index
int index = it - arr.begin();

cout << "Upper bound index of 3: " << index << endl;
```

// lower_bound
// accumulate
// hash<T> object
// size_t datatype
// log2
// ceil
// floor
// abs
// pow
// sqrt
// hypot
// INT_MAX, INT_MIN, LLONG_MAX, LLONG_MIN