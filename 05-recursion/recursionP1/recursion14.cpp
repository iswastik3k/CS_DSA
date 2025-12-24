// Maze Path
// You are given a grid (maze) of size m x n.
// You start at the top‑left corner (0,0) and want to reach the bottom‑right corner (m-1,n-1).
// At each move, you can only:
//     Move right (→), or Move down (↓).

// Your task is to determine how many distinct paths exist from the start to the destination.

#include <iostream>
#include <vector>
using namespace std;

// Start -> 0, 0
// Destn. -> n-1, m-1
// Again we'll assume we're moving from bottom-right to top left to make things easier.
long long countPaths(int n, int m) {
    // Base Cases
    // Possible Path
    if (n == 0 && m == 0) {
        return 1;
    }
    // Path Discarded
    if (n < 0 || m < 0) {
        return 0;
    }

    // At any cell we can go up or left -> n-1 or m-1
    // No. of paths from [i,j] cell = No. of paths from [i][j-1] cell + No. of paths from [i-1][j] cell
    return countPaths(n, m - 1) + countPaths(n - 1, m);
}

int main() {
    int n, m;
    cout << "Enter no. of rows: ";
    cin >> n;
    cout << "Enter no. of columns: ";
    cin >> m;

    cout << "No. of possible paths: " << countPaths(n - 1, m - 1) << endl;

    return 0;
}