// 真子可以通过无为转变将灵魂改变形状，从而将人类变成怪物。为了对抗真子，五条悟老师展开了无量空处 0.5s，一条条信息涌入真子脑海，真子已经奄奄一息之时，突然回光返照，想起了梦中的完美灵魂形状，真子先构筑了一个边长分别为 a，b，c 的三角形，并在三角形内部做了一个面积最大的圆。
// “桀桀桀”，他笑着伸出双手，“无为转变！五条悟接受我最后的防御形态吧！”
// 五条悟咧嘴一笑：“苍！”
// 轰！
// “这么强……我的内切圆竟然如此不堪一击。”
// 那么内切圆半径为多少？

//提示： r = S / c（S是三角形面积， c是三角形半周长），面积可用海伦公式计算
// S = sqrt(p * (p - a) * (p - b) * (p - c))，其中 p = (a + b + c) / 2

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main () {
    int n;
    cin >> n;

    while(n--) {
        double a, b, c;
        cin >> a >> b >> c;
        double p = (a + b + c) / 2; // 半周长
        double S = sqrt(p * (p - a) * (p - b) * (p - c)); // 海伦公式计算三角形面积
        double r = S / p; // 内切圆半径
        cout << fixed << setprecision(2) << r << endl;
    }

    return 0;
}