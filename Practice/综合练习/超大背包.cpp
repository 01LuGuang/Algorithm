#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

int main() {
    int N;
    ll V;
    cin >> N >> V;

    vector<ll> v(N), w(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }

    // dp: key = total_value, value = minimal_volume required
    map<ll, ll> dp;
    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        vector<pair<ll, ll>> new_items;
        for (auto& [val, vol] : dp) {
            ll new_val = val + w[i];
            ll new_vol = vol + v[i];
            if (new_vol <= V) {
                new_items.emplace_back(new_val, new_vol);
            }
        }
        // 合并更新
        for (auto& [nv, nv_vol] : new_items) {
            if (!dp.count(nv)) dp[nv] = nv_vol;
            else dp[nv] = min(dp[nv], nv_vol);
        }
    }

    // 找最大 dp[v] ≤ V 的 value
    ll ans = 0;
    for (auto& [val, vol] : dp) {
        if (vol <= V) {
            ans = max(ans, val);
        }
    }

    cout << ans << endl;
    return 0;
}
