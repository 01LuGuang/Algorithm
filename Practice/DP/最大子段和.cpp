#include <iostream>
#include <vector>

using namespace std;

int MaxSum(vector<int>& nums, int n) {
    int sum = 0, b = 0;
    for(int i = 1; i <= nums.size(); i ++) {
        if(b > 0)
            b += nums[i];
        else 
            b = nums[i];
        if(b > sum)
            sum = b;
    }
    return sum;
}

int  main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    cout << MaxSum(a, n) << endl;

    return 0;
}