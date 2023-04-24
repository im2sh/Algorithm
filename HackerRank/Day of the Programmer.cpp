#include <iostream>
#include <string>

#define programmerDay 256
using namespace std;

int year;
bool flag = false;
int basicDay = 243;
string result;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> year;
}

string solve() {
    int temp = 0;
    if (year < 1917 && year % 4 == 0)
        flag = true;
    else if (year == 1918)
        return "26.09.1918";
    else if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        flag = true;

    if (flag)
        basicDay += 1;
    temp = programmerDay - basicDay;
    result = to_string(temp) + ".09." + to_string(year);

    return result;
}

int main(void) {
    FastIO();
    Init();
    cout << solve();
    return 0;
}

