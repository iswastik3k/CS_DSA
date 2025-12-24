// Compute a^b (a, b -> Natural Nos.)

#include <iostream>
using namespace std;

long long int pow(int a, int b) {
    // Base Cases
    if (a == 1 || a == 0) {
        return a;
    }
    if (b <= 0) {
        return 1;
    }

    // a^b = a * a^(b-1)
    // pow(a,b) = a * pow(a, b-1)
    return a * pow(a, b - 1);
}

int main() {
    int a, b;
    cout << "Enter base: ";
    cin >> a;
    cout << "Enter exponent: ";
    cin >> b;

    cout << "a^b: " << pow(a, b) << endl;

    return 0;
}