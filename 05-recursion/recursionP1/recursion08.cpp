// Nth Fibonacci number  -> Optimized
// We'll drop recursion and compute via tabulation (D.P).
// Bottom-Up D.P (Tabulation)

#include <iostream>
#include <vector>
using namespace std;

long long fibyy(int n) {
    // Smallest sub problem we know the answer of -> fib(0) = 0, fib(1) = 1
    // We'll use these and build the answer upwards.
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    long long prev2(0), prev1(1), curr(0);
    for (int i = 2; i <= n; ++i) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "nth Fibonacci number is: " << fibyy(n) << endl;

    return 0;
}