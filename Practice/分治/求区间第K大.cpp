//给你一个数组，请 O(n)复杂度找出其中第 k大的数。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> array(n);

    for (int i = 0; i < n; i ++) {
        cin >> array[i];
    }

    sort(array.begin(), array.end());//排序的时间复杂度是O(nlogn)

    cout << array[n - k] << endl;

    return 0;

}