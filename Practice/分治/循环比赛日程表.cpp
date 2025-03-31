#include <iostream>
#include <vector>

using namespace std;

void table(vector<vector<int>>& schedule,int n, int startRow, int startCol) {
    //初始化
    // for(int j = 0; j < n; j++) {
    //     schedule[0][j] = j + 1;
    // }
    // for(int i = 0; i < n; i++) {
    //     schedule[i][0] = i + 1;
    // }

    if(n == 1) {
        schedule[startRow][startCol] = 1;
        return;
    }

    int mid = n / 2;

    table(schedule, mid, startRow, startCol); //左上部分

    //复制左上半部分到右下半部分
    for(int i = 0; i < mid; i++) {
        for(int j = 0; j < mid; j++) {
            schedule[startRow + i + mid][startCol + j + mid] = schedule[startRow + i][startCol + j];
        }
    }

    //复制左上部分到右上部分
    for(int i = 0; i < mid; i ++) {
        for(int j = 0; j < mid; j ++) {
            schedule[startRow + i][startCol + j + mid] = schedule[startRow + i][startCol + j] + mid;
        }
    }

    //复制左上部分到左下半部分
    for(int i = 0; i < mid; i++) {
        for(int j = 0; j < mid; j++) {
            schedule[startRow + i + mid][startCol + j] = schedule[startRow + i][startCol + j] + mid;
        }
    }

}

int main() {
    int n;

    while(cin >> n) {
        vector<vector<int>> schedule(n, vector<int>(n, 0));

        table(schedule, n, 0, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << schedule[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}