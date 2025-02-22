#include <iostream>

using namespace std;

typedef struct date {
    int year, month, day;
} Date;

constexpr int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
Date D, Dday;
int day1, day2, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> D.year >> D.month >> D.day;
    cin >> Dday.year >> Dday.month >> Dday.day;
}

int leapyear(Date d1, Date d2) {
    int cnt = 0;
    if (d1.month > 2)
        d1.year++;
    if (d2.month > 2)
        d2.year++;
    for (int i = d1.year; i < d2.year; i++) {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
            cnt++;
    }
    return cnt;
}

int yearToDay(Date d) {
    int date = 0;
    date += d.year * 365;
    for (int i = 0; i < d.month - 1; i++) {
        date += months[i];
    }
    date += d.day;
    return date;
}

void solve() {
    day1 = yearToDay(D);
    day2 = yearToDay(Dday);

    ret = day2 - day1;
    ret += leapyear(D, Dday);

    if (ret >= 365243)
        cout << "gg";
    else
        cout << "D-" << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}