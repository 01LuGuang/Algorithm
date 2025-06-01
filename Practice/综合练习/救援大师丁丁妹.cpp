#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int L, n;
    cin >> L >> n;
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> pos[i];
    }
    
    int min_time = 0, max_time = 0;
    for (int i = 0; i < n; ++i) {
        int current_min = min(pos[i], L + 1 - pos[i]);
        int current_max = max(pos[i], L + 1 - pos[i]);
        min_time = max(min_time, current_min);
        max_time = max(max_time, current_max);
    }
    cout << min_time << " " << max_time << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}