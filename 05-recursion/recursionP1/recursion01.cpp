// Hello Recursion.

#include <iostream>
using namespace std;

void greet(int n) {
    // Base Case
    if (!n) {
        return;
    }

    // Work
    cout << "Hello, I'm recursion. How are you?\n";

    // Recursive call
    greet(n - 1);
}

int main() {
    greet(5);

    return 0;
}