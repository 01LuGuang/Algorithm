//我就说我这么写跟贪心有什么关系。要求最少内存，那么我应该是能改变进程的执行顺序的

//错误代码
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     vector<int> R(n), O(n);
//     int ans = 0, sumO = 0;

//     for(int i = 0; i < n; i ++) {
//         cin >> R[i] >> O[i];
//         int cur = sumO + R[i];
//         if(cur > ans) ans = cur;
//         sumO += O[i];
//     }

//     cout << ans;

//     return 0;
// }

//正确思路：为了尽量少占内存，应该优先执行 R[i]-O[i] 较大的任务。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);

    int ans = 0, sumO = 0;

    for(int i = 0; i < n; i ++) {
        cin >> arr[i].first >> arr[i].second;
    }

    // bool cmp(pair<int,int> &a, pair<int,int> &b) {
    //     return (a.first - a.second) > (b.first - b.second);
    // }
    
    // sort(p.begin(), p.end(), cmp);
    
    // 按照 R[i]-O[i] 从大到小排序， lambda 表达式
    sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b) {
        return (a.first - a.second) > (b.first - b.second);
    });

    for(int i = 0; i < n; i ++) {
        int cur = sumO + arr[i].first;
        if(cur > ans) ans = cur;
        sumO += arr[i].second;
    }

    cout << ans;

    return 0;
}