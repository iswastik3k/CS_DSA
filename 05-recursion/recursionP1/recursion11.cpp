// Stair Path
// You are climbing a staircase that has n steps.
// At each move, you can climb either:
// 1 step, or 2 steps.

// Your task is to determine how many distinct ways you can reach the top of the staircase.

#include <iostream>
using namespace std;

// We'll proceed this question with a reverse engineering mindset:
// No. of paths to climb up n stairs = No. of paths to climb down n stairs
// We'll assumne we're climbinng down stairs, from nth step to 0th to make things easier.
long long countWays(int n) {
    // Base Case
    // Possible Path
    if (n == 0) {
        return 1;
    }
    // Path Discarded
    if (n < 0) {
        return 0;
    }

    // At every step we can take 1 step down or 2 steps down
    return countWays(n - 1) + countWays(n - 2);
}

int main() {
    int n;
    cout << "Enter no. of steps: ";
    cin >> n;

    cout << "No. of distinct paths possible: " << countWays(n) << endl;

    return 0;
}

// OBSERVATION -> This problem is a derivative of Fibonacci Sequence.
// 1 Step 1 way, 2 Steps -> 2 ways, 3 Steps -> 3 ways ...