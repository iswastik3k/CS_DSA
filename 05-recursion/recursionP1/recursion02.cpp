#include <iostream>
using namespace std;

long long int fact(int n) {
    // Base Case
    if (n == 0) {
        return 1;
    }

    // fact(n) = n * fact(n-1)
    return n * fact(n - 1);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "n! = " << fact(n) << endl;

    return 0;
}