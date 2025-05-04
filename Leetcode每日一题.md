**4.11**

[2843. 统计对称整数的数目](https://leetcode.cn/problems/count-symmetric-integers/)

```C++
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for(int i = low; i <= high; i ++) {
            string s = to_string(i);
            int n = s.size();
            if(n % 2 == 0 && reduce(s.begin(), s.begin() + n / 2) == reduce(s.begin() + n / 2, s.end())){
                res ++;
            }
        }
        return res;
    }
};
```



**5.4**

[1128. 等价多米诺骨牌对的数量](https://leetcode.cn/problems/number-of-equivalent-domino-pairs/)

```C++
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        map<pair<int, int>, int> dict;
        for(auto& d : dominoes) {
            auto key = minmax(d[0], d[1]);
            ans += dict[key]++;
        }
        return ans;
    }
};
```



哈希表这么好用吗hhh

[1512. 好数对的数目](https://leetcode.cn/problems/number-of-good-pairs/)

```C++
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for(int x : nums) {
            ans += cnt[x]++;
        }
        return ans;
    }
};
```

