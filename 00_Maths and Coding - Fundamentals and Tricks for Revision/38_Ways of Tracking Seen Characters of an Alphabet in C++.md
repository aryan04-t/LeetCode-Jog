# Ways of Tracking Seen Characters of an Alphabet in C++ 


**Note:** Here the input string has just lowercase characters `a to z`


## 📊 Four Approaches Comparison

### 1️⃣ Unordered Map
```cpp
unordered_map<char, bool> seen;
seen[ch] = true;
if(seen[ch]) { /* already seen */ }
```
- **Space:** O(n) where n = 26 unique chars
- **Loop-Up Time:** O(1) average lookup
- **Use when:** Need to track additional info per char


### 2️⃣ Unordered Set
```cpp
unordered_set<char> seen;
seen.insert(ch);
if(seen.count(ch)) { /* already seen */ }
```
- **Space:** O(n) where n = 26 unique chars  
- **Loop-Up Time:** O(1) average lookup
- **Use when:** Only need presence/absence


### 3️⃣ Boolean Vector
```cpp
vector<int> seen(26, 0);
seen[ch - 'a'] = 1;
if(seen[ch - 'a']) { /* already seen */ }
```
- **Space:** O(26) = O(1)
- **Loop-Up Time:** O(1) direct access
- **Use when:** Only lowercase letters


### 4️⃣ Bit Masking ⭐
```cpp
int seen = 0;                            // this is also called "mask" 
int shifts = (ch - 'a');
int bitPosition = 1 << shifts;           // get bit position
if((seen & bitPosition) == 0) {          // check if not set
    seen |= bitPosition;                 // mark as seen
}
```
- **Space:** O(1) - single integer
- **Loop-Up Time:** O(1) bitwise ops
- **Use when:** Need ultimate space efficiency


## 🎯 Bit Masking Deep Dive

### Core Operations
| Operation | Code | Purpose |
|-----------|------|---------|
| Compute position | `1 << shifts` | Get bit for char |
| Check if seen | `(seen & bitPosition) == 0` | Char bit is unset |
| Mark as seen | `seen \|= bitPosition` | Set the bit |

### Why It Works
- Each of 26 letters maps to 1 bit (0-25)
- Single `int` has 32 bits → enough for a-z
- Example: `'a'→bit 0`, `'c'→bit 2`, `'z'→bit 25`

### Visual Example
```
seen = 0000...0101  (chars 'a' and 'c' seen)
ch = 'b' → bit = 0000...0010
seen & bitPosition = 0  → not seen ✓
seen |= bitPosition → 0000...0111  (now 'a', 'b', 'c' seen)
```

## 📝 Reference Problem
**LeetCode 3760**: Maximum Substrings With Distinct Start - [Solution Link](https://github.com/aryan04-t/LeetCode-Sprint/blob/master/3760.%20Maximum%20Substrings%20With%20Distinct%20Start/03_Most_Optimal_Bit_Masking_Approach.cpp)

**Key Insight:** Bit masking achieves O(1) space vs O(26) for vector, O(26) used by map/set also

## 💡 Quick Decision Guide
- **Bit masking** → Lowercase a-z only, need best space
- **Vector** → Lowercase a-z, simpler code
- **Set** → Any chars, only need presence
- **Map** → Any chars, need extra data per char