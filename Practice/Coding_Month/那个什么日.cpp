#include <iostream>
#include <iomanip>

using namespace std;

bool Leap(int year) {
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0); 
}

int main () {
    int x;
    cin >> x;
    int year = 1970, month = 1, day = 1;

    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    day += x;

    while(true) {
        int days_in_year = 365 + (Leap(year) ? 1 : 0);
        if(day > days_in_year) {
            day -= days_in_year;
            year ++;
        } else {
            break;
        }
    }

    while(true) {
        int days_in_month = month_days[month - 1];
        if(Leap(year) && month == 2 ) days_in_month = 29;
        if(day > days_in_month) {
            day -= days_in_month;
            month ++;
        } else {
            break;
        }
    }

    cout << year << "-" << setfill('0') << setw(2) << month << "-" << setfill('0') << setw(2) << day << endl;

    return 0;
}