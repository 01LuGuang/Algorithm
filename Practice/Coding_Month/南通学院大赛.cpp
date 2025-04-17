//知道最大公约数和最小公倍数，求满足这个条件的整数对

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 求最大公约数
int gcd(int a, int b) {
    while(b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> ans;
        // a = n * k, b = n * l, 且 gcd(a, b) = n, lcm(a, b) = m
        // => lcm(a, b) = a * b / gcd(a, b) = n * k * n * l / n = n * k * l
        // 所以 k * l = m / n，且 gcd(k, l) = 1
        if(m % n != 0) {
            // 不存在
        } else {
            int mul = m / n;
            for(int k = 1; k * k <= mul; ++k) {
                if(mul % k == 0) {
                    int l = mul / k;
                    if(gcd(k, l) == 1) {
                        int a = n * k;
                        int b = n * l;
                        if(a > b) swap(a, b);
                        ans.emplace_back(a, b);
                    }
                }
            }
            sort(ans.begin(), ans.end());
            for(auto &p : ans) {
                cout << p.first << " " << p.second << "\n";
            }
        }
    }
    return 0;
}