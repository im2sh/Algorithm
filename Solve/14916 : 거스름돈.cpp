#include <iostream>

using namespace std;

int N;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    int start = N / 5;
    int remain = (N - start * 5) % 2;
    while (remain != 0) {
        if (start == 0) {
            cout << -1;
            return;
        }
        start -= 1;
        remain = (N - start * 5) % 2;
    }
    cout << start + (N - start * 5) / 2;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}