#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> matrix(N, vector<int>(M));
    vector<vector<int>> dp(N, vector<int>(M, 0)); // dp[i][j]表示到达(i,j)的最大路径和

    // 输入矩阵
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    // 初始化起点
    dp[0][0] = matrix[0][0];

    // 初始化第一行
    for (int j = 1; j < M; j++) {
        dp[0][j] = dp[0][j - 1] + matrix[0][j];
    }

    // 初始化第一列
    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
    }

    // 动态规划计算其余部分
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
        }
    }

    // 输出结果
    cout << dp[N - 1][M - 1] << endl;

    return 0;
}