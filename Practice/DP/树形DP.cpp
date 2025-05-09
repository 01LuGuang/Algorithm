#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 6010;
int H[N];
vector<int> tree[N];
int dp[N][2]; //dp[u][0] 不来 dp[u][1] 来
bool has_parent[N]; //寻找祖宗结点

void dfs(int u) {
    dp[u][1] = H[u]; //来的话加上自己的快乐值
    for(int v : tree[u]) {
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]); //直系领导没来，下属来不来都可
        dp[u][1] += dp[v][0]; //直系领导来了，下属不能来
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i ++) cin >> H[i];

    for(int i = 1; i < n; i ++) {
        int l, k;
        cin >> l >> k;
        tree[k].push_back(l);//k 处存放的是子节点 l
        has_parent[l] = true;//标记有父节点的结点，方便后续找祖宗结点
    }

    //处理森林的情况
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        if(!has_parent[i]) {
            dfs(i); //从祖宗结点开始深度优先搜索
            ans += max(dp[i][0], dp[i][1]); //祖宗结点的最大快乐值
        }
    }

    cout << ans << endl;
    
    return 0;
}