// Power function (Natural no.s) -> Optimized with D.P
// Logarithmic T.C -> O(log2(b))
// We'll use Tabulation

#include <iostream>
using namespace std;

long long power(int a, int b) {
    // Smallest sub problem we know the answer of -> a^0 = 1
    long long res = 1;
    while (b > 0) {
        if (b % 2) {
            res *= a;
        }
        a *= a;
        b /= 2;
    }

    return res;
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