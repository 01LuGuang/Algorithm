#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(4), b(4);

    while(n --) {
        scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
        scanf("%d%d%d%d", &b[0], &b[1], &b[2], &b[3]);
        int s0;
        scanf("%d", &s0);

        double min_score = 1e9;
        bool win = false;

        //枚举a，b队友的情况
        for(int i = 0; i < 4; i ++) {
            for(int j = 0; j < 4; j++) {
                //本题并没有考虑到同一个职业的情况，这些先注释掉，进阶的时候再写
                //if(i == j) continue; //不能是同一个职业
                //标记一下
                // int used[4] = {0};
                // used[i] = used[j] = 1;
                //挑选小鸡的职业
                for(int k = 0; k < 4; k ++) {
                    //if(used[k]) continue;
                    int sum = a[i] + b[j];
                    int temp = s0 - sum;
                    int min_val = max(30, temp);//因为要赢下对局，所以起码要 >= s0
                    if(min_val <= 160) {
                        win = true;
                        if(min_val < min_score * 10) min_score = min_val / 10.0;
                    }
                }
            }
        }
        if(win)
            printf("%.1f\n", min_score);
        else
            printf("Sad\n");
    }

    return 0;
}