// Maze Path (Print Paths)
// You are given a grid (maze) of size m x n.
// You start at the top‑left corner (0,0) and want to reach the bottom‑right corner (m-1,n-1).
// At each move, you can only:
//     Move right (→), or Move down (↓).

// Your task is to print paths from the start to the destination.

#include <iostream>
#include <vector>
using namespace std;

// Start -> 0, 0
// Destn. -> n-1, m-1
// Again we'll assume we're moving from bottom-right to top left to make things easier.
void countPaths(int n, int m, string path) {
    // Base Cases
    // Possible Path
    if (n == 0 && m == 0) {
        cout << path << endl;
        return;
    }
    // Path Discarded
    if (n < 0 || m < 0) {
        return;
    }

    // At any cell we can go up or left -> n-1 or m-1
    countPaths(n, m - 1, path + "R");
    countPaths(n - 1, m, path + "D");
}

int main() {
    int n, m;
    cout << "Enter no. of rows: ";
    cin >> n;
    cout << "Enter no. of columns: ";
    cin >> m;

    cout << "Possible paths: \n";
    countPaths(n - 1, m - 1, "");

    return 0;
}