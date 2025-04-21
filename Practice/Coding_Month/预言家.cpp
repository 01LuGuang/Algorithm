#include <iostream>

using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    int ax = (a - 1) / n, ay = (a - 1) % n;
    int bx = (b - 1) / n, by = (b - 1) % n;

    if((abs(ax - bx) == 1 && ay == by) || (abs(ay - by) == 1 && ax == bx)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}