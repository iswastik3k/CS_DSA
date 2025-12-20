# Arrays — Introduction

## Overview
An array is a contiguous block of memory that stores elements of the same type. Elements are indexed by integers starting at 0. Arrays provide constant-time indexed access and excellent cache locality.

## Definitions & Concepts
- Static array: fixed size known at compile-time (e.g., `int a[10];`).
- Dynamic array: allocated at runtime (e.g., `new int[n]` in C++).
- `std::array` (C++): fixed-size wrapper with an STL-like interface.
- Contiguous memory layout: element i is at address `base + i * sizeof(element)`.

## When to use
- When you need O(1) index access.
- When size is known and fixed or memory layout/locality matters.
- For low-level performance-sensitive code or interfacing with C APIs.

## Common operations & complexity
- Access by index: O(1)  
- Traversal (read/write all elements): O(n)  
- Insertion/deletion at arbitrary position (static arrays): O(n)  
- Insertion/deletion at end (dynamic arrays, amortized): amortized O(1)  
- Search (unsorted): O(n); binary search on sorted array: O(log n)

## Useful patterns & algorithms
- Prefix sums — preprocess for O(1) range-sum queries.  
- Sliding window — subarray problems constrained by sum/length.  
- Two pointers — pair/interval problems (especially on sorted arrays).  
- Kadane’s algorithm — maximum subarray sum in O(n).  
- Sorting + binary search — repeated membership/ordered queries.

## C++ examples
Static array:
```cpp
int a[5] = {1,2,3,4,5};
int x = a[2]; // 3
```

Dynamic array (raw pointer):
```cpp
int n = 10;
int *b = new int[n];
b[0] = 1;
delete[] b;
```

`std::array`:
```cpp
#include <array>
std::array<int,5> arr = {1,2,3,4,5};
arr.at(2); // bounds-checked
```

Prefix-sum example:
```cpp
vector<int> prefix(n+1, 0);
for (int i = 0; i < n; ++i) prefix[i+1] = prefix[i] + a[i];
// sum of a[l..r] = prefix[r+1] - prefix[l]
```

Kadane example:
```cpp
int best = a[0], curr = a[0];
for (int i = 1; i < n; ++i) {
  curr = max(a[i], curr + a[i]);
  best = max(best, curr);
}
```

## Pros and Cons
Pros:
- Fast indexed access (O(1))  
- Low memory overhead; great cache locality

Cons:
- Fixed size for static arrays  
- Costly middle insertion/deletion (O(n))  
- Manual memory management if using raw pointers

## Pitfalls & tips
- Avoid out-of-bounds indexing.  
- Prefer `std::array` or `std::vector` in modern C++ for safety and lifetime management.  
- Use `const` references when passing large arrays/vectors to functions to avoid copies.