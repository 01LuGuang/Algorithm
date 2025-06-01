#include <iostream>
#include <vector>
using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(vector<string>& grid, int x, int y, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != 'W') {
        return;
    }
    grid[x][y] = '.'; // 标记为已访问
    for (int i = 0; i < 8; ++i) {
        dfs(grid, x + dx[i], y + dy[i], n, m);
    }
}

int countWaterPuddles(vector<string>& grid, int n, int m) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'W') {
                dfs(grid, i, j, n, m);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    cout << countWaterPuddles(grid, n, m) << endl;
    return 0;
}