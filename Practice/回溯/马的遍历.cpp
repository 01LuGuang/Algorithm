#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool visited[26][26];
vector<pair<int, int>> path;
vector<pair<int, int>> bestPath;
bool found = false;

// 用于字典序比较
bool isBetter(const vector<pair<int, int>>& a, const vector<pair<int, int>>& b) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].second != b[i].second)
            return a[i].second < b[i].second;
        if (a[i].first != b[i].first)
            return a[i].first < b[i].first;
    }
    return false;
}

void dfs(int x, int y, int cnt) {
    if (cnt == n * m) {
        if (!found || isBetter(path, bestPath)) {
            bestPath = path;
            found = true;
        }
        return;
    }

    vector<pair<int, int>> nextMoves;

    // 生成所有可能的下一个移动
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
            nextMoves.emplace_back(nx, ny);
        }
    }

    // 排序以获得字典序最小路径
    sort(nextMoves.begin(), nextMoves.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
    });

    for (auto [nx, ny] : nextMoves) {
        visited[nx][ny] = true;
        path.emplace_back(nx, ny);
        dfs(nx, ny, cnt + 1);
        path.pop_back();
        visited[nx][ny] = false;
    }
}

int main() {
    cin >> n >> m;

    found = false;

    // 尝试从每一个起点出发
    for (int i = 0; i < n && !found; ++i) {
        for (int j = 0; j < m && !found; ++j) {
            memset(visited, false, sizeof(visited));
            path.clear();

            visited[i][j] = true;
            path.emplace_back(i, j);
            dfs(i, j, 1);
        }
    }

    if (!found) {
        cout << "impossible" << endl;
    } else {
        for (auto [x, y] : bestPath) {
            cout << char('A' + y) << x + 1;
        }
        cout << endl;
    }

    return 0;
}
