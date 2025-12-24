// Power function (Natural no.s) -> Optimized
// Logarithmic T.C -> O(log2(b))

#include <iostream>
using namespace std;

long long power(int a, int b) {
    // We know:
    // 2^4 = 2^2 * 2^2
    // 2^5 = 2 * 2^2 * 2^2
    // Generally:
    // if b is even -> pow(a,b) = pow(a, b/2) * pow(a, b/2)
    // if b is odd -> pow(a,b) =  a * pow(a, b/2) * pow(a, b/2)
    // We'll store pow(a, b/2) in a variable -> half

    // Base Case
    if (b == 1) {
        return a;
    }
    if (b == 0) {
        return 1;
    }

    long long half = power(a, b / 2);

    return ((b % 2) ? a * half * half : half * half);
}

int main() {
    int a, b;
    cout << "Enter base: ";
    cin >> a;
    cout << "Enter power: ";
    cin >> b;

    cout << "a^b is: " << power(a, b) << endl;

    return 0;
}