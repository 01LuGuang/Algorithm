#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1,0);
    vector<int> b(n + 1,0);

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(int i = k - 1; i <= n; i ++) {
        int j = 0;
        b[j] = a[i];
    }

    for(int i = 1; i <= n; i ++) {
        cout << b[i] << " ";
    }

    return 0;
}