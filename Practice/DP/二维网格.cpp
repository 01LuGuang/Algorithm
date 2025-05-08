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

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> beauty(N + 1, vector<int>(M + 1, 0));

    for(int i = 1; i <= N; i ++) {
        for(int j = 1; j <= M; j ++) {
            cin >> beauty[i][j];
        }
    }

    for(int i = 1; i <= N; i ++) {
        for(int j = 1; j <= M; j ++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + beauty[i][j];
        }
    }

    cout << dp[N][M] << endl;

    return 0;
}
