#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    //m[i][j] 表示从第 i 个到第 j 个矩阵的连乘次数的最小值
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));

    for(int len = 2; len <= n; len ++) { // len 是区间长度
        for(int i = 1; i <= n - len + 1; i ++) {
            int j = i + len -1;
            m[i][j] = INT_MAX; // 初始化为最大值
            for(int k = i; k < j; k ++) {
                int t = m[i][k] + m[k + 1][j] + a[i - 1] * a[k] * a[j]; // 计算当前的连乘次数
                if(t < m[i][j]) {
                    m[i][j] = t; // 更新最小值
                }
            }
        }
    }

    cout << m[1][n] << endl;

    return 0;
}