// Print 1 to n and n to 1.

// Essence of pre-call / post-call work.

#include <iostream>
using namespace std;

// Post Call Work
void dis1toN(int n) {
    // Base case
    if (n <= 0) {
        return;
    }

    // Recursive Call
    dis1toN(n - 1);

    // Work
    cout << n << " ";
}

// Pre Call Work
void disNto1(int n) {
    // Base case
    if (n <= 0) {
        return;
    }

    // Wrok
    cout << n << " ";

    // Recursive Call
    disNto1(n - 1);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    dis1toN(n);
    cout << endl;
    disNto1(n);
    cout << endl;

    return 0;
}