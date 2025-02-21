#include <iostream>

using namespace std;

typedef long long ll;

ll N;
ll factorial[21];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    factorial[0] = 1;
    for (int i = 1; i <= 20; i++)
        factorial[i] = factorial[i - 1] * i;
}

void solve() {
    if (N == 0) {
        cout << "NO";
        return;
    }
    for (int i = 20; i >= 0; i--) {
        if (N >= factorial[i])
            N -= factorial[i];
        if (N == 0) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}