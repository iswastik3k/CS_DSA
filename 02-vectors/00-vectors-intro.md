# Vectors (std::vector) — Introduction

## Overview
`std::vector` is the dynamic array container from the C++ Standard Library. It provides contiguous storage, random access, and automatic resizing. It is the go-to container for resizable arrays with STL integration.

## Key properties
- Contiguous memory (like arrays)  
- Random access iterators (O(1) element access)  
- Automatic resizing with amortized O(1) `push_back`  
- Exposes `size()` and `capacity()` to manage storage

## When to use
- When you need a resizable contiguous container.  
- When you want to use STL algorithms or iterators.  
- When append and indexed access are common operations.

## Basic usage / syntax
```cpp
#include <vector>
std::vector<int> v;            // empty vector
v.push_back(5);                // append
int x = v[0];                  // no bounds check
int y = v.at(0);               // throws out_of_range if invalid
v.size(); v.capacity(); v.reserve(100);
v.clear(); v.pop_back();
```

## Important member functions & complexity
- `operator[]` / `at()`: O(1)  
- `front()`, `back()`: O(1)  
- `push_back()`: amortized O(1)  
- `pop_back()`: O(1)  
- `insert(position, val)`: O(n)  
- `erase(position)`: O(n)  
- `reserve(n)`: O(n) when reallocation occurs  
- `resize(n)`: O(n) when expanding/contracting  
- `data()`: pointer to contiguous storage

## Amortized analysis
When capacity is exhausted, the vector allocates a larger buffer and copies/moves elements; typical growth strategies yield amortized O(1) push performance.

## Iterator invalidation (common rules)
- `push_back` may invalidate iterators if it triggers reallocation.  
- `insert`/`erase` invalidate iterators at/after the change point (details depend on operation/implementation).

## Patterns & techniques
- Use `reserve()` when the expected final size is known to avoid repeated reallocations.  
- Prefer `emplace_back()` for in-place construction of non-trivial objects.  
- Use iterators/range-based `for` loops for readability.  
- For frequent middle inserts/erases consider `deque` or `list`.

## Examples
Reserve and push:
```cpp
std::vector<int> v;
v.reserve(100);
for (int i = 0; i < 100; ++i) v.push_back(i);
```

Rotate (reverse-method):
```cpp
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
```

## Pros and Cons
Pros:
- Dynamic size, contiguous memory (cache-friendly)  
- STL-compatible and versatile

Cons:
- Middle insertion/erase is O(n)  
- Iterator invalidation on reallocation

## Debugging tips
- Use `at()` during development to catch bounds errors.  
- Monitor `capacity()` vs `size()` to understand reallocation behavior.