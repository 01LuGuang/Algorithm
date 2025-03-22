//经典递归问题：汉诺塔

/*问题思路：
当n=1时，只要将编号为1的圆盘从柱子A直接移到柱子C上即可。
当n>1时，就需要借助另外一根柱子来移动。将n个圆盘由A移到C上可以分解为以下几个步骤：

(1)  将A柱子上的n-1个圆盘借助C柱子移到B柱子上;
(2)  把A柱子上剩下的一个圆盘从A柱子移到C柱子上;
(3)  最后将剩下的n-1个圆盘借助A柱子从B柱子移到C柱子上。 这里注意递归的杆的身份的变化
*/

#include <iostream>
#include <cstdio>

using namespace std;

long long step;

//将n个盘子转移，src，dst，aux分别为源，目的，辅助杆
void Hanoi(int num, char src, char dst, char aux) {
    if(num == 1) {
        printf("step %lld: %d From %c To %c\n", step, 1, src, dst);
        step++;
    }
    else {
        Hanoi(num - 1, src, aux, dst);
        printf("step %lld: %d From %c To %c\n", step, num, src, dst);
        step++;
        Hanoi(num - 1,aux, dst, src);
    }

}

int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        long long total = (1LL << n) - 1;//总步数
        printf("%lld\n",total);

        step = 1;
        Hanoi(n, 'A', 'C', 'B');
    }

    return 0;
}