//0-1背包问题

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int N, V;
        cin >> N >> V;
        vector<int> magic(N), summon(N);
        vector<int> dp(V + 1, 0); // dp数组初始化为0

        for(int i = 0; i < N; i++) {
            cin >> magic[i];
        }
        for(int i = 0; i < N; i++) {
            cin >> summon[i];
        }

        //dp核心代码
        for(int i = 0; i < N; i ++) {
            for(int j = V; j >= summon[i]; j--) {
                dp[j] = max(dp[j], dp[j - summon[i]] + magic[i]);
            }
        }

        cout << dp[V] << endl;
    }

    return 0;
}