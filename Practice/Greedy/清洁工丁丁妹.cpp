#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int Case;
    cin >> Case;

    while (Case--) {
        int n, T;
        cin >> n >> T;
        vector<pair<int, int>> segs(n); // 用pair存储每个区间的L和R
        for (int i = 0; i < n; ++i) {
            cin >> segs[i].first >> segs[i].second;
        }
        // 按左端点排序
        sort(segs.begin(), segs.end());

        int now = 1; // 当前需要覆盖的起点
        int cnt = 0; // 选择的区间数量
        int i = 0;
        bool ok = true;
        while (now <= T) {
            int maxR = -1;
            // 在所有L<=now的区间中，选R最大的
            while (i < n && segs[i].first <= now) {
                if (segs[i].second > maxR) maxR = segs[i].second;
                ++i;
            }
            if (maxR < now) { // 无法推进，覆盖失败
                ok = false;
                break;
            }
            now = maxR + 1; // 推进到下一个未覆盖点
            ++cnt;
        }
        if (ok) cout << cnt << endl;
        else cout << -1 << endl;
    }

    return 0;
}