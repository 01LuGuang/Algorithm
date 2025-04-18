//区间DP问题
//状态：dp[i][j]表示从i到j的石子合并的最小代价
//sum[i][j]表示从i到j的石子和
//转移方程：dp[i][j] = min(dp[i][k] + dp[k + 1][j] + sum(i, j))，其中i <= k < j

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> stones(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<int> sum(n + 1, 0); // 前缀和数组

    //前缀和快速处理
    for(int i = 1; i <= n; i ++) {
        cin >> stones[i];
        sum[i] = sum[i - 1] + stones[i]; // 前缀和
    }

    //dp
    for (int len = 2; len <= n; len++) { // 枚举区间长度
        for (int i = 1; i <= n - len + 1; i++) { // 枚举区间起点
            int j = i + len - 1; // 区间终点
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) { // 枚举分割点
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }

    cout << dp[1][n] << endl; 

    return 0;
}