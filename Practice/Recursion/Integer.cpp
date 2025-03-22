//整数划分问题

/*
将正整数 n 表示成一系列正整数之和，n=n1+n2+n3+...nk,其中,n1>=n2>=n3>=...nk>=1
​正整数 n 的这种表示称为正整数 n 的划分，正整数 n 的不同的划分个数称为正整数 n 的划分数，记作 p(n)
*/

//问题思路：在正整数 n 的划分中，将最大加数 n1 不大于 m 的划分个数记为 q(n, m)，可以建立 q(n,m)的递归关系：
//1. q(n, 1) = 1, n >= 1，当最大加数 n1 不大于 1 时，任何正整数 n 只有一中划分形式：n = 1 + 1 + 1 + ... + 1
//2. q(n, m) = q(n, n), m >= n. 最大加数 n1 实际上不能大于 n, 因此 q(1, m) = 1
//3. q(n, n) = 1 + q(n, n - 1). 正整数 n 的划分由 n1 = n 的划分和 n1 <= n - 1的划分组成
//4. q(n, m) = q(n, m - 1) + q(n - m, m), n > m > 1。 正整数 n 的最大加数 n1 不大于 m 的划分由 n1 = m的划分和 n1 <= m - 1 的划分组成
//递归式如下：
/*
            1                               n = 1, m = 1
            q(n, n)                         n < m
q(n, m) =   1 + q(n, n - 1)                 n = m
            q(n, m - 1) + q(n - m, m)       n > m > 1

*/

#include <iostream>

using namespace std;

int q(int n, int m) {
    if((n < 1) || (m < 1))
        return 0;
    if((n == 1) || (m == 1))
        return 1;
    if(n < m)
        return q(n, n);
    if(n == m)
        return q(n, m - 1) + 1;
    return(q(n, m - 1) + q(n - m, m));
}

int main() {
    int n;

    while(cin >> n) {
        cout << q(n, n) << endl;
    }

    return 0;
}