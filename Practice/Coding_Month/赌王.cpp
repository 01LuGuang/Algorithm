#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    if(m >= 1 * n && m <= 6 * n) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}