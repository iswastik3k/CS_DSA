// Nth Fibonacci number
// Multiple calls -> Exponential T.C and S.C

#include <iostream>
using namespace std;

long long fiby(int n) {
    // Base Case
    // fib(0) =  0, fib(1) = 1
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    // fib(n) = fib(n-1) + fib(n-2)
    // Multiple Recusive Calls -> 2 Calls for each n
    return fiby(n - 1) + fiby(n - 2);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "nth Fibonacci number is: " << fiby(n) << endl;

    return 0;
}