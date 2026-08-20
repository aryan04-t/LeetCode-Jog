- What are lambda functions in C++ 

- How to declare a lambda function, and what does different parts of a lambda function mean 
What are there use cases 

- lambda's parameter can be defined with function<> template and auto keyword as well to store them 

- Example of lambda function use case 


# Same all above for functors 


// When to use Functors in C++ -> when initializeing a STL template with custom logic -> When you want to write a hasher for unordered_set or unordered_map template 

// When to use lambdas, when you want to pass a custom logic comparator to stl helper function calls -> like custom sort, custom min_element or max_element finding logic, etc. -> you can also use normal functions in these cases instead of lambdas 

_ _ _ _ _ 


# Lambda [] Capture Clause Options 

int x = 10;
vector<int> nums = {1, 2, 3};

// [&] - Capture ALL external variables BY REFERENCE
auto lambda1 = [&]() { return x + nums[0]; };  // Can access x and nums

// [=] - Capture ALL external variables BY VALUE (copy)
auto lambda2 = [=]() { return x + nums[0]; };  // Gets copy of x and nums

// [&x] - Capture ONLY x by reference
auto lambda3 = [&x]() { return x * 2; };

// [x] - Capture ONLY x by value
auto lambda4 = [x]() { return x * 2; };

// [&, x] - Capture all by reference EXCEPT x (by value)
auto lambda5 = [&, x]() { return x + nums[0]; };

// [] - Capture NOTHING (can't access external variables)
auto lambda6 = []() { return 42; };  // Can't use x or nums!