//归并过程中来计算逆序对的数量

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Merge_sort(vector<int>& a, int l, int r, vector<int>& tmp) {
    if (r - l <= 1) return 0;

    int mid = (l + r) / 2;
    int count = 0;

    count += Merge_sort(a, l, mid, tmp); // 递归排序左半部分
    count += Merge_sort(a, mid, r, tmp); // 递归排序右半部分

    int i = l, j = mid, k = l;
    while(i < mid && j < r) {
        if(a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
            count += mid - i; // 计算逆序对
        }
    }

    while(i < mid) {
        tmp[k++] = a[i++];
    }
    while(j < r) {
        tmp[k++] = a[j++];
    }

    for(int i = l; i < r; i++) {
        a[i] = tmp[i];
    }
    return count;
}


int main() {
    int n;

    while(cin >> n) {
        vector<int> a(n), tmp(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int count = Merge_sort(a, 0, n, tmp);

        cout << count << endl;
    }
}