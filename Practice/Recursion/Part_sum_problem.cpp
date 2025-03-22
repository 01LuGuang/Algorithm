//二叉树递归思路：https://blog.csdn.net/S1998F/article/details/104124378

#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> a;

//构造二叉树（加或者不加）
//从 i 开始，当前和为 sum 是否能构造出和为 K 的子集
bool dfs(int i, int sum) {

    //遍历结束，判断是否等于K
    if(i == N) {
        return sum == K;
    }

    if(dfs(i + 1, sum)) {
        return true;
    }

    if(dfs(i + 1, sum + a[i])) {
        return true;
    }

    return false;
}


int main() {
    cin >> N >> K;

    a.resize(N);
    // vector<int> a(N);
    for(int i = 0; i < N; i ++) {
        cin >> a[i];
    }

    if(dfs(0, 0)) {
        cout << "YE5";
    }
    else {
        cout << "N0";
    }

    return 0;
}


//不通过全局变量的传参
// #include <iostream>
// #include <vector>
// using namespace std;

// // 从 i 开始，当前和为 sum 是否能构造出和为 K 的子集
// // a: 输入数组, N: 数组长度, K: 目标和
// bool dfs(int i, int sum, const vector<int>& a, int N, int K) {
//     // 遍历结束，判断是否等于 K
//     if (i == N) {
//         return sum == K;
//     }
//     // 不选第 i 个数
//     if (dfs(i + 1, sum, a, N, K)) {
//         return true;
//     }
//     // 选第 i 个数
//     if (dfs(i + 1, sum + a[i], a, N, K)) {
//         return true;
//     }
//     return false;
// }

// int main() {
//     int N, K;
//     cin >> N >> K;
    
//     vector<int> a(N);
//     for (int i = 0; i < N; i++) {
//         cin >> a[i];
//     }
    
//     if (dfs(0, 0, a, N, K)) {
//         cout << "YE5";
//     } else {
//         cout << "N0";
//     }
    
//     return 0;
// }


// 8分
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int N, K;
//     cin >> N >> K;
//     vector<int> a(N);
    
//     for (int i = 0; i < N; i++) {
//         cin >> a[i];
//     }
    
//     int subsetCount = 1 << N; 
//     for (int mask = 0; mask < subsetCount; mask++) {
//         int sum = 0;
//         for (int i = 0; i < N; i++) {
//             if (mask & (1 << i)) {
//                 sum += a[i];
//             }
//         }
//         if (sum == K) {
//             cout << "YES" << endl;
//             return 0;
//         }
//     }
//     cout << "N0" << endl;
//     return 0;
// }
