//题目描述
// 小聪家很有钱，但有钱不代表他傻。现在他要开始买房了，他琢磨着不能买多了，于是将 n 栋房纳入了考虑范围。
// 如果这栋房性价比高，他就会买；否则，他就不会买。
// 现在会给出每栋房的总价 v，与每栋房的大小 s，你可以算出每栋房单位面积内的房价，若该单位面积内的房价超出小聪的接受范围 w，则不买；否则，买。

//输入：第一行两个整数n， w
//接下来 n 行，每行两个整数 v， s
//输出： n 行，如果买输出 Yes， 否则输出 NO， 并换行

#include <iostream>

using namespace std;

int main () {
    //cin cout 速度接近 scanf printf
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w;
    cin >> n >> w;

    //endl 不仅换行，还会强制刷新输出缓冲区，导致大量 IO 操作，效率很低。
    while(n--) {
        int v, s;
        cin >> v >> s;
        //double price = (double)v / s;
        if(v <= w * s) {
            cout << "Yes\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}