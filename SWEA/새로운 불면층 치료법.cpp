#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int TC, N, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    ret = 0;
    cin >> N;
}

bool isCheck(int num) {
    if ((num & ((1 << 10) - 1)) == ((1 << 10) - 1))
        return true;

    return false;
}

void go() {
    int num = 0;
    int cnt = 0;
    int t = N;
    while (true) {
        string temp = to_string(t);
        for (int i = 0; i < temp.length(); i++) {
            int digit = temp[i] - '0';
            num |= (1 << digit);
        }
        if (isCheck(num))
            break;
        t = (N * (++cnt));
    }
    ret = t;
}

void solve() {
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        Init();
        go();

        cout << '#' << i << ' ' << ret << '\n';
    }
}

int main(void) {
    FastIO();
    solve();
    return 0;
}