//最优调度问题
//前缀和

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, n;
    cin >> T;

    while(T--) {
        cin >> n;
        vector<int> time(n);
        for(int i = 0; i < n; i ++) {
            cin >> time[i];
        }
    
        sort(time.begin(), time.end());
        long long sum = 0, wait = 0;
        for(int i = 0; i < n; i ++) {
            sum += wait;
            wait +=time[i];//前缀和
        }
    
        cout << sum << endl;
    }

    return 0;
}