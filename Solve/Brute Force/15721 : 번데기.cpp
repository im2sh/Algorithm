#include <iostream>

using namespace std;

int A, T, ret;
bool flag;
int r = 1;
int total = 7;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> A >> T >> flag;
}

void solve() {
    int temp = 4;
    while (T > temp) {
        temp += 4 + r++;
        total += 4 + 2 * (r + 1);
    }
    temp -= (4 + r - 1);
    total -= (4 + 2 * (r + 1));

    if (T - temp <= 2)
        ret = (!flag) ? total + 2 * (T - temp) - 1 : total + 2 * (T - temp);
    else
        ret = (!flag) ? total + 4 + (T - temp - 2) : total + 4 + (r + 1) + (T - temp - 2);

    cout << ret % A;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}