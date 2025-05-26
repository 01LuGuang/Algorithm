#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 20;
bool isPrime[2 * MAX_N]; // 存放是否为素数（最大 2*n）

void initPrimes(int limit) {
    fill(isPrime, isPrime + limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= limit; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }
}

int n;
vector<bool> used;
vector<int> ring;

void dfs(int pos) {
    if (pos == n) {
        if (isPrime[ring[n - 1] + ring[0]]) { // 判断首尾是否为素数
            for (int i = 0; i < n; ++i) {
                cout << ring[i] << (i == n - 1 ? '\n' : ' ');
            }
        }
        return;
    }

    for (int i = 2; i <= n; ++i) {
        if (!used[i] && isPrime[ring[pos - 1] + i]) {
            used[i] = true;
            ring[pos] = i;
            dfs(pos + 1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n;
    initPrimes(2 * n);

    used = vector<bool>(n + 1, false);
    ring = vector<int>(n);
    ring[0] = 1;
    used[1] = true;

    dfs(1);
    return 0;
}
