#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, n;
    cin >> T;

    while(T--) {
        cin >> n;
        int end = -1;//上一个活动的结束时间
        int ans = 0; //可以做的活动数量
        vector<pair<int, int>> thing(n);

        for(int i = 0; i < n; i ++) {
            cin >> thing[i].first >> thing[i].second; //开始时间和结束时间
        }

        // 按照结束时间排序
        sort(thing.begin(), thing.end(), [](pair<int, int>&a, pair<int, int> &b) {
            return a.second < b.second;
        });

        // 贪心算法，选择结束时间最早的活动
        for(int i = 0; i < n; i ++) {
            if(thing[i].first >= end) {
                ans ++;
                end = thing[i].second;
            }
        }

        cout << ans << endl;
    }

    return 0;
}