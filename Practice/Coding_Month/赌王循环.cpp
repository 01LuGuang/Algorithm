//思路：直接用两个vector来替换其中长度为 k 的 0 序列
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n + 1,0);

    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int j  = 1;
    for(int i = k; i < n; i ++) { //注意边界 k 到 n-1
        b[j] = a[i];
        j ++;
    }

    for(int i = 1; i <= n; i ++) {
        cout << b[i] << " ";
    }

    return 0;
}