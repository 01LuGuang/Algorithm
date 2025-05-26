#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10005;
vector<int> tree[MAXN];
int val[MAXN];        // 每个节点挂的钱
int subtreeSum[MAXN]; // 每个节点的子树和

// 计算以node为根的子树的总和
int dfs(int node, int parent) {
    int sum = val[node];
    for (int child : tree[node]) {
        if (child != parent) {
            sum += dfs(child, node);
        }
    }
    subtreeSum[node] = sum;
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;

    // 从1开始编号
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
    }

    // 构建树
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    // 预处理所有子树和，从根节点1开始
    dfs(1, 0);

    // 回答每个查询
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        cout << subtreeSum[x] << endl;
    }

    return 0;
}
