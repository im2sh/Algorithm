#include <iostream>

using namespace std;

int x;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> x;
}

int solve() {
    int line = 64;
    int cnt = 0;
    while (line > 0) {
        if (x & line)
            cnt++;
        line /= 2;
    }
    return cnt;
}

int main(void) {
    FastIO();
    Init();
    cout << solve() << "\n";
    return 0;
}
