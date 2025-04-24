#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

// 生成一个数的最小旋转值
int min_rotation(int x) {
    string s = to_string(x);
    string min_s = s;
    for (size_t i = 1; i < s.size(); ++i) {
        rotate(s.begin(), s.begin() + 1, s.end()); // 把最前面一个字符转到末尾
        if (s[0] != '0')  // 不能以0开头的旋转才合法
            min_s = min(min_s, s);
    }
    return stoi(min_s);
}

int main() {
    int L, R;
    cin >> L >> R;

    unordered_map<int, int> freq;

    // 统计每个旋转最小值出现的次数
    for (int x = L; x <= R; ++x) {
        int key = min_rotation(x);
        freq[key]++;
    }

    long long result = 0;
    for (const auto& [key, count] : freq) {
        if (count >= 2) {
            result += 1LL * count * (count - 1) / 2;
        }
    }

    cout << result << endl;
    return 0;
}
