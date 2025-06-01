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

vector<int> parent;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[y] = x;
    }
}

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    parent.resize(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    int total_cost = 0;
    for (const Edge& e : edges) {
        if (find(e.u) != find(e.v)) {
            union_set(e.u, e.v);
            total_cost += e.cost;
        }
    }
    return total_cost;
}

int main() {
    int n;
    cin >> n;
    vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cost;
            cin >> cost;
            if (i < j) {  // 避免重复添加边
                edges.emplace_back(i, j, cost);
            }
        }
    }
    cout << kruskal(n, edges) << endl;
    return 0;
}