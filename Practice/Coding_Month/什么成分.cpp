//这题挺有意思的，我的思考方式第一次不好解决这个问题

#include <iostream>
using namespace std;

int main() {
    int L, R;
    cin >> L >> R;
    int cnt = 0;
    for (int a = L; a < R; ++a) {
        int x = a, len = 0, pow10 = 1;
        while (x) {
            len++;
            pow10 *= 10;
            x /= 10;
        }
        pow10 /= 10;
        int b = a;
        // 用一个简单的数组记录本 a 已经统计过的 b
        int seen[10] = {0}; // 最多10位数
        for (int i = 1; i < len; ++i) {
            int last = b % pow10;
            int first = b / pow10;
            b = last * 10 + first;
            // 位数不变，且 b > a 且 b <= R
            if (b > a && b <= R) {
                // 检查 b 是否已经统计过
                bool flag = false;
                for (int j = 0; j < i; ++j) {
                    if (seen[j] == b) flag = true;
                }
                if (!flag) {
                    seen[i - 1] = b;
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}