#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    double sum = 0.0;

    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        sum += a[i];
    }

    double avg = sum / n;

    printf("%.2f\n", avg);
    return 0;
}