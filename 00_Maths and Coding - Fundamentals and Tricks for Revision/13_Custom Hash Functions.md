# Custom Hash Functions: 

What is a good custom hash function describe in 1 line 

_ _ _ _

A good hash function aims for the `avalanche effect`, meaning a small change in the input (e.g., flipping a single bit) results in a large, unpredictable change in the output (about half the bits in the hash are flipped). 

This randomness helps ensure that different inputs are mapped widely across the range of possible hash values, thus avoiding collisions.

Purpose of good hash function is to efficiently spread the input data across the hash space to avoid collisions. 

_ _ _ _

In C++ which data types don't have a hash function for them in unordered_map and unodered_set constructor 

Example of a hash function for pair in c++ for an unordered_set 

- Why hash function of functional header is used 
- Hash functor of stl use case 
- return type of hash function of stl (What is size of size_t in bits and bytes, and what range does it encompases in itself)
- best easiest ways to distribute hashes to prevent collisions 


# What are functors in C++


// These can be used for unordered_set, unordered_map for keys which don't have native hash functions like vector<data_type> or pair<data_type, data_type> 