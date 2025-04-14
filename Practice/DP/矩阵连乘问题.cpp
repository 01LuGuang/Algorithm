#include <iostream>
#include <vector>

using namespace std;

void MatrixChain(int *p, int n, int **m, int **s) {
    for(int i = 1; i <= n; i ++) {
        m[i][i] = 0; //对角线元素为0
    }

    for(int r = 2; r <= n; r++) {
        
    }
}