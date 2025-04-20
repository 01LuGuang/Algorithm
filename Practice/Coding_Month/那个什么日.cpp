#include <iostream>
#include <iomanip>
using namespace std;

// 判断闰年
bool is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int x;
    cin >> x;
    int year = 1970, month = 1, day = 1;
    // 每月天数（平年）
    int month_days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    day += x; // 加上x天

    while (true) {
        int days_in_year = is_leap(year) ? 366 : 365;
        if (day > days_in_year) {
            day -= days_in_year;
            year++;
        } else {
            break;
        }
    }

    while (true) {
        int days_in_month = month_days[month];
        if (month == 2 && is_leap(year)) days_in_month = 29;
        if (day > days_in_month) {
            day -= days_in_month;
            month++;
        } else {
            break;
        }
    }

    cout << setw(4) << setfill('0') << year << '-'
         << setw(2) << setfill('0') << month << '-'
         << setw(2) << setfill('0') << day << endl;
    return 0;
}