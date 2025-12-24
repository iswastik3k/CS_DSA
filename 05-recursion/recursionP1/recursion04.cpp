// Print sum from 1 to n

#include <iostream>
using namespace std;

int sum(int n) {
    // Base case
    if (n <= 0) {
        return 0;
    }
    // Sum(n) = n + Sum(n-1)
    // Sum(5) = 5 + Sum(4)
    return n + sum(n - 1);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Sum: " << sum(n) << endl;

    return 0;
}