//选数问题，洛谷P1036,我居然之前写过，一点印象没有。一年前写的吧可能

//思路：DFS搜索所有组合，然后判断是否素数


//远古代码
// #include <iostream>
// #include <cstdio>
// using namespace std;
// bool isprime(int a){
//     if(a == 1) return false;
//     for(int i = 2; i * i <= a; i++)
//         if(a % i == 0)
//             return false;
//     return true;
// }

// int n,k;
// int a[25];
// long long ans;

// void dfs(int m, int sum, int startx){
//     if(m == k){
//         if(isprime(sum))
//             ans++;
//         return ;
//     }
//     for(int i = startx; i < n; i++)
//         dfs(m + 1, sum + a[i], i + 1);
//     return ;
// }

// int main(){
//     scanf("%d%d",&n,&k);
//     for(int i = 0; i < n; i++)
//         scanf("%d",&a[i]);
//     dfs(0, 0, 0);
//     printf("%d\n",ans);
//     return 0;
// }

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if(num < 2) return false;

    for(int i = 2; i * i < num; i ++) {
        if(num % i == 0)
            return false;
    }
    return true;
}

// idx: 当前考虑的下标
// count: 当前已选元素个数
// k: 需要选取的元素个数
// sum: 当前组合的和
// nums: 存储所有输入数字的数组
// res: 记录满足条件（和为素数）的组合数量
void DFS(int idx, int count, int k, int sum, const vector<int>& nums, int &res) {
    //选够 k 个数，判断
    if(count == k) {
        if(isPrime(sum))
            res ++;
        return;
    }
    //遍历结束
    if(idx >= nums.size()) return;
    
    //选这个数
    DFS(idx + 1, count + 1, k, sum + nums[idx], nums, res);
    //不选这个数
    DFS(idx + 1, count, k, sum, nums, res);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
    }

    int res = 0;
    DFS(0,0,k,0,nums,res);
    cout << res << endl;

    return 0;
}