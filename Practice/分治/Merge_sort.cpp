//归并排序(MERGE-SORT)是利用归并的思想实现的排序方法，
//该算法采用了经典的分治(divide-and-conquer)策略

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void Merge_sort(vector<int>& a, int l, int r, vector<int>& tmp){
    if(r - l <= 1) return; // 只有一个元素，直接返回
    
    //[l, r), [l, mid), [mid, r)
    int mid = (l + r) / 2;
    Merge_sort(a, l, mid, tmp); // 递归排序左半部分
    Merge_sort(a, mid, r, tmp); // 递归排序右半部分

    merge(a.begin() + l, a.begin() + mid,
        a.begin() + mid, a.begin() + r,
        tmp.begin() + l);

    for(int i = l; i < r; i++){
        a[i] = tmp[i];
    }
}

int main(){
    int n;

    while(cin >> n) {
        vector<int> a(n), tmp(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        Merge_sort(a, 0, n, tmp);

        for(int i = 0; i < n; i ++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}