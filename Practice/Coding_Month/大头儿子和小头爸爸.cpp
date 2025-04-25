#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int max_sum = -1, ed = -1;//ed 为极差, .ax_sum 为最多吃了多少饭
    //每个人都需要吃饭， 从 1 开始
    for(int i = 1; i * a <= n; i ++) {
        for(int j = 1; j * b <= n; j ++) {
            for(int k = 1; k * c <= n; k ++) {
                int sum = i * a + j * b + k * c;
                if(sum > n) continue;
                if(sum > max_sum) {
                    max_sum = sum;
                    ed = max({i *a, j * b, k * c}) - min({i * a, j * b, k * c});//注意多参数用法
                } else if(sum == max_sum) {
                    int temp = max({i * a, j * b, k * c}) - min({i * a, j * b, k * c});
                    if(temp < ed) {
                        ed = temp;
                    }
                }
            }
        }
    }

    //如果有人没法吃饭
    if(max_sum == -1) {
        cout << "-1 -1" << endl;
    } else {
        cout << max_sum << " " << ed << endl;
    }

    return 0;
}