#include <iostream>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll count_mod(ll L, ll R, int r) {
    return (R - r) / 3 - (L - 1 - r) / 3;
}

int main() {
    ll n, L, R;
    cin >> n >> L >> R;

    // cnt[i] 表示 [L, R] 中 模3 == i 的数的个数
    ll cnt[3];
    cnt[0] = count_mod(L, R, 0);
    cnt[1] = count_mod(L, R, 1);
    cnt[2] = count_mod(L, R, 2);

    // dp[i] 表示当前总和 mod 3 == i 的方案数
    ll dp[3] = {1, 0, 0};

    //用滚动数组来优化空间
    for (ll i = 0; i < n; ++i) {
        ll old_dp[3] = {dp[0], dp[1], dp[2]};
        for (int j = 0; j < 3; ++j) {
            dp[j] = (old_dp[(j - 0 + 3) % 3] * cnt[0] +
                    old_dp[(j - 1 + 3) % 3] * cnt[1] +
                    old_dp[(j - 2 + 3) % 3] * cnt[2]) % MOD;
        }
    }

    cout << dp[0] << endl;

    return 0;
}