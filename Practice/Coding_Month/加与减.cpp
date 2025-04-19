#include <iostream>

using namespace std;

void f(int a, int b, int c) {
    if (a + b == c) {
        cout << "+" << endl;
    } else if(a - b == c) {
        cout << "-" << endl;
    }
}


int main() {
    int n;
    cin >> n;

    while(n --) {
        int a, b, c;
        cin >> a >> b >> c;

        f(a, b, c);
    }

    return 0;
}