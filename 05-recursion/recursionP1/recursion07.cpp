// Nth Fibonacci number  -> Optimized
// We'll handle multiple calls with D.P
// Top Down D.P + Memoization

#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp;

long long fiby(int n) {
    // Base Case
    // fib(0) = 0, fib(1) = 1
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    // fib(n) = fib(n-1) + fib(n-2)
    // We'll compute fib(n) ONLY IF it has not been calculated by some previous call already
    if (dp[n] == -1) {
        return dp[n] = fiby(n - 1) + fiby(n - 2);
    } else {
        return dp[n];
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    dp.assign(n + 1, -1);

    cout << "nth Fibonacci number is: " << fiby(n) << endl;

    return 0;
}