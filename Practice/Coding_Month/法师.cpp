// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i ++) {
//         cin >> a[i];
//     }

//     for(int i = 0 ; i < n; i ++) {
//         for(int j = 0; j < n; j ++) {
//             if((j + 1) % a[i] == 0) {
//                 cout << "*";
//             } else {
//                 cout << " ";
//             }
//         }
//         cout << endl;
//     }

//     return 0;
// }


#include <iostream>

using namespace std;

bool star(int row, int col, int t) {
    return (col % t == 0);
}

int main() {
    int n;
    cin >> n;
    int t;
    for(int i = 1; i <= n; i++) {
        cin >> t;
        for(int j = 1; j <= n; j++) {
            if(star(i, j, t)) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}