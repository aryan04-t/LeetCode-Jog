- Classes also end with a semi colon 
- When define a custom hasher function (In cases like, for pairs or vectors in unordered_set or unordered_map) - always remember, the operator () should define it type as const 

Example: size_t operator()(const pair<int, int>& p) const

That const after the parameter list means:

“This method doesn’t modify the internal state of the object it’s called on.”

Formally, it means inside the function you cannot modify any data members of this.

Cause the Hasher object is created with the const reference so it doens't wants the object to be changed at all as the hasher class is just a functor with operator() definition in it - that's why the operator() has to be declared as const 


# In a class all things are by default private, use "public" label explicitly to define operator() in side a class based functor 

# In writing custom hash functors in C++, remember to marke operator() overloaded definition as well as const 

# C++ range start is inclusive and end is exclusive [start, end)