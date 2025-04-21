#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t, s, p;
    cin >> t >> s >> p;
    int arr[3] = {t, s, p};

    sort(arr, arr + 3);

    if (arr[1] - arr[0] == arr[2] - arr[1]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
