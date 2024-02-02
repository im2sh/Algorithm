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
    int i = 1;
    while (N > i) {
        N -= i;
        i++;
    }

    if (i % 2 == 1)
        cout << i + 1 - N << '/' << N << '\n';
    else
        cout << N << '/' << i + 1 - N << '\n';
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}