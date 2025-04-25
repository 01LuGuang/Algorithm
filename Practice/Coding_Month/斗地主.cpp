#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int num = y - x + 1;
    int ans = num * (num - 1) * (num - 2) * (num - 3);

    cout << ans << endl;
    return 0;
}