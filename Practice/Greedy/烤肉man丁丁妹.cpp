//物体可以拿一部分，背包问题

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int M, n;
    cin >> M >> n;
    double ans = 0.0;

    //排序时不仅要根据单位美味度排，还要保持美味度和重量的一一对应关系
    vector<pair<double, pair<int, int>>> meat;

    for(int i = 0; i < n; i ++) {
        int V, W;
        cin >> V >> W;
        double avgV = double(V) / W; //单位美味度
        meat.push_back({avgV, {V, W}});
    }

    // 按照单位美味度从大到小排序 ，注意 lambda 表达式的格式
    sort(meat.begin(), meat.end(), [](pair<double, pair<int, int>> &a, pair<double, pair<int, int>> &b){
        return a.first > b.first;
    });

    for(int i = 0; i < n; i ++) {
        if(M >= meat[i].second.second) {
            ans += meat[i].second.first; //美味度
            M -= meat[i].second.second;
        } else {
            ans += M * meat[i].first;
            break;
        }
    }

    printf("%.3f\n", ans);

    return 0;
}