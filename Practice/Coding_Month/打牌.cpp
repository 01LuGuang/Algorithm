#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x, y, l, r;
    cin >> n >> x >> y >> l >> r;

    int emyin = 0, StepNeuro = 0;

    for(int i = l; i <= r; i ++) {
        if(i % x == 0 && i % y == 0) {
            emyin += i;
        }
        
        if(i % x == 0 || i % y == 0) {
            StepNeuro += i;
        }
    }

    cout << emyin << " " << StepNeuro << endl;

    return 0;
}