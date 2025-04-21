#include <iostream>

using namespace std;

int main() {
    int A[32];
    long long  x = 0;//注意 2 ^ 31 就超出 int 的范围了！！！
    for(int i = 0; i < 32; i ++) {
        cin >> A[i];
        x += A[i] * (1LL << i);
    }
    cout << x << endl;

    return 0;
}