#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double x;
    cin >> x;

    int k = floor(x / 2); 
    double ans;
    if (x >= 2 * k && x <= 2 * k + 1) {
        ans = x - floor(x);
    } else if(x >= 2 * k + 1 && x <= 2 * k + 2){
        ans = floor(x) - x + 1;
    }
    
    printf("%.2f", ans);
    
    return 0;
}