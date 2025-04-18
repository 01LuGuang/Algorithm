//最长严格递增子序列问题

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// //O(n^2)的动态规划解法
// int lengthOfLIS(vector<int>& nums) {
//     int n = nums.size();
//     if(n == 0) return 0;

//     vector<int> dp(n, 1); // dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度
//     for(int i = 0; i < n; i ++) {
//         for(int j = 0; j < i; j ++) {
//             if(nums[i] > nums[j]) {
//                 dp[i] = max(dp[i], dp[j] + 1); // 更新 dp[i]
//             }
//         }
//     }
//     return *max_element(dp.begin(), dp.end()); // 返回最长递增子序列的长度
// }

//O(n log n)
int lengthOfLIS(vector<int>& nums) {
    vector<int> dp; 
    for(int num : nums) {
        auto it = lower_bound(dp.begin(), dp.end(), num); // 找到第一个大于等于 num 的位置
        if(it == dp.end()) {
            dp.push_back(num); // 如果没有找到，说明 num 可以扩展最长递增子序列
        } else {
            *it = num; // 否则更新这个位置的值
        }
    }
    return dp.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    cout << lengthOfLIS(a) << endl;

    return 0;
}