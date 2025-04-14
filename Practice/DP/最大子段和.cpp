#include <iostream>
#include <vector>

using namespace std;

int MaxSum(vector<int>& nums) {
    int sum = nums[0], b = nums[0];
    for(int i = 1; i < nums.size(); i ++) {
        if(b > 0)
            b += nums[i];
        else 
            b = nums[i];
        if(b > sum)
            sum = b;
    }
    return sum;
}

// int  main() {
//     int n;
//     scanf("%d", &n);;
//     vector<int> a(n);

//     for(int i = 0; i < n; i ++) {
//         scanf("%d", &a[i]);
//     }

//     printf("%d\n", MaxSum(a));
//     return 0;
// }
int  main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    cout << MaxSum(a) << endl;

    return 0;
}