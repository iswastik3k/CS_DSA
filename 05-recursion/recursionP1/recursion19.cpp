// Print ZigZag
// n = 1 -> 111
// n = 2 -> 211121112
// n = 3 -> 321112111232111211123

#include <iostream>
using namespace std;

void zigy(int n) {
    // Base Case
    if (!n) {
        return;
    }
    cout << n;  // Pre
    zigy(n - 1);
    cout << n;  // In
    zigy(n - 1);
    cout << n;  // Post
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    zigy(n);
    cout << endl;

    return 0;
}