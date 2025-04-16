//题目描述：
//吴谦违法被逮捕后的某一天，用超能力逃跑了，此时吴谦被传送到了离警局 x 米处的地方。警察在 t 秒后发现吴谦逃跑，以 v 的速度立马去追。
//而吴谦因为过度劳累无法逃跑，只能再一次发挥超能力，但超能力有冷却，两次超能力间隔时间必须不小于 t2 秒。
//请问在警察追到他之前，他能否再一次发动超能力。

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n --) {
        int x, t, v, t2;
        cin >> x >> t >> v >> t2;
        if(v * (t2 - t) >= x) {
            cout << "Nice!\n";
        } else {
            cout << "NO!!!\n";
        }
    }

    return 0;
}