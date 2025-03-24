//全排列问题
//全排列的时间复杂度为 O(n!)，空间复杂度为 O(n)

//递归法
//如何递归：求1~n的全排列，可以先固定1，然后求n-1的全排列，然后固定2，求n-2的全排列，以此类推
//需要一个交换函数，固定某个数时需要和1交换，这一轮递归结束后再换回来，以此类推

//回溯法不会

//无法按照字典序输出,采取先排序再输出
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector <string> res;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//递归函数
//num表示当前固定的数，n表示总数，a表示数组
void permutation(int num, int n, vector<int> &a) {
    //结束，打印
    if(num == n) {
        string s;
        for(int i = 1; i <= n; i++) {
            s += to_string(a[i]);//转换成字符串然后拼接
        }
        res.push_back(s);
        return;
    }

    for(int i = num; i <= n; i ++) {
        swap(a[num], a[i]);
        permutation(num + 1, n, a);//应该递归到num+1，不然一直无线循环
        //递归完记得恢复原始状态
        swap(a[num], a[i]);
    }

}

int main() {
    int n;
    scanf("%d", &n);

    // int a[n + 1];
    vector <int> a(n + 1);
    //初始化数组
    for(int i = 1; i <= n; i++) {
        a[i] = i;
    }

    permutation(1, n, a);

    sort(res.begin(), res.end());

    for(auto &i : res) {
        printf("%s\n", i.c_str());
    }
    
    return 0;
}


/******************************************************* */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> perm(n);

    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
    }
    
    do {
        for (int i = 0; i < n; i++)
            cout << perm[i];
        cout << "\n";
    } while (next_permutation(perm.begin(), perm.end()));
    
    return 0;
}
