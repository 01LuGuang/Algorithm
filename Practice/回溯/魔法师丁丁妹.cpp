#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 构建字符级有向图
void buildGraph(const vector<string>& reactions, unordered_map<char, vector<char>>& graph) {
    for (const string& r : reactions) {
        if (r.size() >= 2)
            graph[r.front()].push_back(r.back());
    }
}

// BFS 检查 b 是否能到达 m
bool bfs(char start, char target, unordered_map<char, vector<char>>& graph) {
    queue<char> q;
    unordered_set<char> visited;
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        char curr = q.front();
        q.pop();
        if (curr == target) return true;
        for (char neighbor : graph[curr]) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> reactions(n);
        for (int i = 0; i < n; ++i) {
            cin >> reactions[i];
        }
        unordered_map<char, vector<char>> graph;
        buildGraph(reactions, graph);
        cout << (bfs('b', 'm', graph) ? "Yes." : "No.") << endl;
    }
    return 0;
}
