#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    //特殊情况直接处理
    if(N == 0 || M == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0)); //dp[i][j]表示到达(i,j)的最大美丽值
    vector<vector<int>> beauty(N + 1, vector<int>(M + 1, 0));

    for(int i = 1; i <= N; i ++) {
        for(int j = 1; j <= M; j ++) {
            cin >> beauty[i][j];
        }
    }

    //初始化第一行和第一列
    for(int i = 1; i <= N; i ++) {
        dp[i][1] = dp[i - 1][1] + beauty[i][1]; //第一列只能从上面来
    }
    for(int j = 1; j <= M; j ++) {
        dp[1][j] = dp[1][j - 1] + beauty[1][j]; //第一行只能从左边来
    }

    for(int i = 2; i <= N; i ++) {
        for(int j = 2; j <= M; j ++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + beauty[i][j];
        }
    }

    cout << dp[N][M] << endl;

    return 0;
}
