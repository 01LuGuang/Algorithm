//找不到重叠子问题，而且看不出来是否要用状态转移方程，实则直接贪心解决

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int sum = 0;

    vector<int> cnt(26, 0); // 统计每个字母的出现次数
    for (char c : s) {
        cnt[c - 'a'] ++;
    }

    sort(cnt.begin(), cnt.end(), greater<int>());

    for(int i = 0; i < 26; i ++) {
        sum += cnt[i] * (26 - i);
    }

    cout << sum << endl;
    
    return 0;
}
