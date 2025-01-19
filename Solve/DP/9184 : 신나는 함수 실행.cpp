#include <iostream>

using namespace std;

int A, B, C;
int DP[21][21][21];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {

}

void Input() {
    cin >> A >> B >> C;
}

int go(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (a > 20 || b > 20 || c > 20)
        return go(20, 20, 20);

    if (DP[a][b][c])
        return DP[a][b][c];

    if (a < b && b < c) {
        DP[a][b][c] = go(a, b, c - 1) + go(a, b - 1, c - 1) - go(a, b - 1, c);
        return DP[a][b][c];
    }

    DP[a][b][c] = go(a - 1, b, c) + go(a - 1, b - 1, c) + go(a - 1, b, c - 1) - go(a - 1, b - 1, c - 1);
    return DP[a][b][c];
}

void solve() {
    while (true) {
        Input();
        if (A == -1 && B == -1 && C == -1)
            break;
        cout << "w(" << A << ", " << B << ", " << C << ") = " << go(A, B, C) << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}