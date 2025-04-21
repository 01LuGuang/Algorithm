// #include <iostream>

// using namespace std;

// int f(int n){
//     if(n < 2) return n;
//         return f(n - 1) + f(n - 2);
// }

// int main() {
//     int n;
//     cin >> n;

//     cout << f(n) << endl;

//     return 0;
// }

//迭代写法
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 2) {
        cout << n << endl;
        return 0;
    }

    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }

    cout << b << endl;
    return 0;
}
