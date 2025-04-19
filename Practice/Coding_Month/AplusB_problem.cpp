//懒得写了，抄一份

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 翻转数字字符串，保留符号
string reverse_number(int num) {
    string s = to_string(num);
    if (s[0] == '-') {
        reverse(s.begin() + 1, s.end());
    } else {
        reverse(s.begin(), s.end());
    }
    // 去除前导零
    int start = (s[0] == '-') ? 1 : 0;
    while (s.size() > start + 1 && s[start] == '0') {
        s.erase(start, 1);
    }
    return s;
}

int main() {
    int result = 0;
    int normal_cnt = 0; // 正常计算次数
    string line;
    while (getline(cin, line)) {
        if (line == "#") break;
        char op;
        int x;
        // 解析操作符和数字
        if (line.size() < 2) {
            cout << "invalid input" << endl;
            continue;
        }
        op = line[0];
        try {
            x = stoi(line.substr(1));
        } catch (...) {
            cout << "invalid input" << endl;
            continue;
        }

        bool valid = true, divided_zero = false;
        int new_result = result;
        switch (op) {
            case '+': new_result = result + x; break;
            case '-': new_result = result - x; break;
            case '*': new_result = result * x; break;
            case '/':
                if (x == 0) {
                    divided_zero = true;
                } else {
                    new_result = result / x;
                }
                break;
            default:
                valid = false;
        }

        if (!valid) {
            cout << "invalid input" << endl;
            continue;
        }
        if (divided_zero) {
            cout << "divided by zero" << endl;
            continue;
        }

        // 正常计算
        normal_cnt++;
        if (normal_cnt % 3 == 0) {
            // 翻转
            string rev = reverse_number(new_result);
            cout << rev << endl;
            // 更新结果为翻转后的数
            result = stoi(rev);
            // 此次不计入正常计算
            normal_cnt = 0;
        } else {
            cout << new_result << endl;
            result = new_result;
        }
    }
    return 0;
}