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

//洛谷：P2871 [USACO07DEC] Charm Bracelet S
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> W(N), V(N);
    vector<int> dp(M + 1, 0); // dp数组初始化为0

    for(int i = 0; i < N; i ++) {
        cin >> W[i] >> V[i];
    }

    for(int i = 0; i < N; i ++) {
        for(int j = M; j >= W[i]; j --) {
            dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
        }
    }

    cout << dp[M] << endl;

    return 0;
}
