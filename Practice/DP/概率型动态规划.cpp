#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<float> p(n);//每颗菜的发芽概率
    vector<vector<float>> dp(n + 1, vector<float>(k + 1, 0));//表示前 i 个种子中，恰好有 j 个萌芽的概率。

    for(int i = 0; i < n; i ++) {
        cin >> p[i];
    }

    dp[0][0] = 1;// 初始化第 0 个种子，恰好有 0 个萌芽的概率为 1
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i && j <= k; j ++) {
            dp[i][j] = dp[i - 1][j] * (1 - p[i - 1]);// 第 i 个种子不发芽的概率
            if(j > 0) {
                dp[i][j] += dp[i - 1][j - 1] * p[i - 1];// 第 i 个种子发芽的概率
            }
        }
    }

    printf("%.4f\n", dp[n][k]);

    return 0;
}