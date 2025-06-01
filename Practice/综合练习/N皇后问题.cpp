#include <iostream>
#include <vector>
using namespace std;

int total = 0;

void backtrack(int row, int n, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
    if (row == n) {
        total++;
        return;
    }
    for (int col = 0; col < n; ++col) {
        int d1 = row - col + n;  // 主对角线
        int d2 = row + col;      // 副对角线
        if (!cols[col] && !diag1[d1] && !diag2[d2]) {
            cols[col] = diag1[d1] = diag2[d2] = true;
            backtrack(row + 1, n, cols, diag1, diag2);
            cols[col] = diag1[d1] = diag2[d2] = false;  // 回溯
        }
    }
}

int solveNQueens(int n) {
    total = 0;
    vector<bool> cols(n, false);
    vector<bool> diag1(2 * n, false);  // 主对角线范围：row - col ∈ [-n+1, n-1]
    vector<bool> diag2(2 * n, false);  // 副对角线范围：row + col ∈ [0, 2n-2]
    backtrack(0, n, cols, diag1, diag2);
    return total;
}

int main() {
    int n;
    while (cin >> n) {
        cout << solveNQueens(n) << endl;
    }
    return 0;
}