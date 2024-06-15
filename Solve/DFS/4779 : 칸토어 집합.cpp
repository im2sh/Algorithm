#include <iostream>
#include <cmath>

using namespace std;

int N;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {

}

void go(int n) {
    int size = pow(3, n - 1);
    if (n == 0) {
        cout << "-";
        return;
    }

    go(n - 1);
    for (int i = 0; i < size; i++) {
        cout << " ";
    }
    go(n - 1);
}

void solve() {
    while (cin >> N) {
        go(N);
        cout << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
