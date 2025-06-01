#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, cost;
    Edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

vector<int> parent, rank_;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // 路径压缩
    }
    return parent[x];
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank_[x] < rank_[y]) {
        parent[x] = y;
    } else {
        parent[y] = x;
        if (rank_[x] == rank_[y]) {
            rank_[x]++;
        }
    }
}

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    parent.resize(n + 1);  // 点编号从1开始
    rank_.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    int total_cost = 0, selected_edges = 0;
    for (const Edge& e : edges) {
        if (find(e.u) != find(e.v)) {
            union_set(e.u, e.v);
            total_cost += e.cost;
            selected_edges++;
            if (selected_edges == n - 1) break;  // 提前终止
        }
    }
    return total_cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    edges.reserve(m);  // 预分配空间
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        edges.emplace_back(x, y, c);
    }
    cout << kruskal(n, edges) << endl;
    return 0;
}