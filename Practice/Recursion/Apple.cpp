//分苹果 即 整数划分问题
/*把 M 个同样的苹果放在 N 个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？
注意5,1,1和1,5,1是同一种分法。*/

/*这个问题其实是一个整数划分问题，但这里分法要求盘子是“同样的”（即无序的），所以排列顺序无关紧要。
我们用函数 f(M, N) 表示把 M 个苹果放到 N 个盘子中的分法数。*/

/*
情况1: 每个盘子至少有一个apple 分法数为 f(M - N, N)
情况2: 至少有一个盘子是空的 分法数为 f(M, N - 1)
两种情况包括了所有情况，递归关系为：f(M,N) = f(M - N, N) + f(M, N - 1)

特殊情况：1.(边界条件) M = 0 or N = 1，只有一种分法 f(0, N) = 1 and f(M, 1) = 1 
        2. N > M 时， f(M, N) = f(M,M)
*/

#include <cstdio>

using namespace std;

int divide(int M, int N) {
    if(M == 0 || N == 1)
        return 1;
    if(N > M)
        return divide(M,M);
    else
        return divide(M - N, N) + divide(M, N - 1);
}

int main() {
    int m, n;
    while(scanf("%d %d", &m, &n) == 2) {
        printf("%d\n", divide(m,n));
    }
    return 0;
}