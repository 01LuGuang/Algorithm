#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t --) {
        int n;
        cin >> n;
        int even = 0, odd = 0;
        vector<int> cp(n);

        for(int i = 0; i < n; i++) {
            cin >> cp[i];
            //是拿到的糖果总数而不是糖果包的数量
            if(cp[i] % 2 == 0) {
                even += cp[i];
            } else {
                odd += cp[i];
            }
        }

        if(odd >= even) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}