#include <iostream>

using namespace std;

long long N;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    if (N % 2 == 1) {
        cout << "SK";
    } else {
        cout << "CY";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}