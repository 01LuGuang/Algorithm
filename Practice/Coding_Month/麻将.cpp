#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    double sum = 0.0;

    for(int i = 0; i < n; i ++) {
        cin >> x;
        sum += x;
    }

    //printf("%.2f\n", sum / n);
    cout << fixed << setprecision(2) << sum / n << endl;
    return 0;
}