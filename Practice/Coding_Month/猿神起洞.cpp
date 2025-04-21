#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double x;
    cin >> x;

    int k = x / 2; // 找到最大的k，使2^k <= x
    double left = pow(2, k), mid = pow(2, k) + 1, right = pow(2, k) + 2;
    double ans;
    if (x >= pow(2, k) && x <= pow(2, k) + 1) {
        ans = x - floor(x);
    } else {
        ans = floor(x) - x + 1;
    }
    cout << fixed << setprecision(2) << ans << endl;
    
    return 0;
}