#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[21]; // 邻接表（编号1~20）
vector<vector<int>> allPaths; // 保存所有合法路径
vector<int> path;
bool visited[21];

int start;

void dfs(int current, int depth) {
    if (depth == 20) {
        // 回到起点，构成环
        for (int next : adj[current]) {
            if (next == start) {
                path.push_back(start);
                allPaths.push_back(path);
                path.pop_back();
                break;
            }
        }
        return;
    }

    for (int next : adj[current]) {
        if (!visited[next]) {
            visited[next] = true;
            path.push_back(next);
            dfs(next, depth + 1);
            path.pop_back();
            visited[next] = false;
        }
    }
}

int main() {
    // 输入图
    for (int i = 1; i <= 20; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[i].push_back(a);
        adj[i].push_back(b);
        adj[i].push_back(c);
    }

    // 起点
    cin >> start;

    // 初始化
    path.push_back(start);
    visited[start] = true;

    // 开始DFS
    dfs(start, 1);

    // 排序（字典序）
    sort(allPaths.begin(), allPaths.end());

    // 输出
    int idx = 1;
    for (const auto& p : allPaths) {
        cout << idx++ << ":  ";
        for (size_t i = 0; i < p.size(); ++i) {
            if (i > 0) cout << " ";
            cout << p[i];
        }
        cout << "\n";
    }

    return 0;
}
