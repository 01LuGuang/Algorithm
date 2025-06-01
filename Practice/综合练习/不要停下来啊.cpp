#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int bfs(vector<string>& grid, int n, int m, int sx, int sy) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    int count = 1;  // 起点也算

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != '#') {
                visited[nx][ny] = true;
                q.push({nx, ny});
                count++;
            }
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        int sx = -1, sy = -1;
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '@') {
                    sx = i, sy = j;
                }
            }
        }
        cout << bfs(grid, n, m, sx, sy) << endl;
    }
    return 0;
}