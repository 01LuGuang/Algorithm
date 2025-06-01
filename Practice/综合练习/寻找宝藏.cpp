#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    vector<Point> points;
    Point start(0, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 'x') {
                start = Point(i, j);
            } else if (grid[i][j] == 'g') {
                points.emplace_back(i, j);
            }
        }
    }
    points.insert(points.begin(), start); // points[0] is start, others are treasures

    int K = points.size();
    vector<vector<int>> dist(K, vector<int>(K, -1));

    // Precompute all pairs shortest path using BFS
    for (int i = 0; i < K; ++i) {
        Point src = points[i];
        queue<Point> q;
        vector<vector<int>> local_dist(N, vector<int>(M, -1));
        q.push(src);
        local_dist[src.x][src.y] = 0;

        while (!q.empty()) {
            Point current = q.front();
            q.pop();
            for (int d = 0; d < 8; ++d) {
                int nx = current.x + dx[d];
                int ny = current.y + dy[d];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && local_dist[nx][ny] == -1) {
                    local_dist[nx][ny] = local_dist[current.x][current.y] + 1;
                    q.push(Point(nx, ny));
                }
            }
        }

        for (int j = 0; j < K; ++j) {
            Point dest = points[j];
            dist[i][j] = local_dist[dest.x][dest.y];
        }
    }

    if (K == 1) {
        cout << 0 << endl;
        return 0;
    }

    // DP[mask][u] : mask is the set of collected treasures, u is the current point
    int mask_size = 1 << K;
    vector<vector<int>> dp(mask_size, vector<int>(K, INT_MAX));
    dp[1][0] = 0; // start at point 0 (start), mask only includes start

    for (int mask = 1; mask < mask_size; ++mask) {
        for (int u = 0; u < K; ++u) {
            if (dp[mask][u] == INT_MAX) continue;
            for (int v = 0; v < K; ++v) {
                if (dist[u][v] == -1) continue;
                if (!(mask & (1 << v))) {
                    int new_mask = mask | (1 << v);
                    if (dp[new_mask][v] > dp[mask][u] + dist[u][v]) {
                        dp[new_mask][v] = dp[mask][u] + dist[u][v];
                    }
                }
            }
        }
    }

    int full_mask = (1 << K) - 1;
    int min_steps = INT_MAX;
    for (int u = 1; u < K; ++u) {
        if (dp[full_mask][u] != INT_MAX && dist[u][0] != -1) {
            min_steps = min(min_steps, dp[full_mask][u] + dist[u][0]);
        }
    }

    cout << min_steps << endl;

    return 0;
}