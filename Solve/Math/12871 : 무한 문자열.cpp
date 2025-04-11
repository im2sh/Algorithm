#include <iostream>

using namespace std;

string S, T, retA, retB;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> S >> T;
}

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GCD(b, a % b);
    }
}

int go(int a, int b) {
    return a * b / GCD(a, b);
}

void solve() {
    int temp = go(S.size(), T.size());

    for (int i = 0; i < temp / S.size(); i++)
        retA += S;

    for (int i = 0; i < temp / T.size(); i++)
        retB += T;

    if (retA == retB)
        cout << 1;
    else
        cout << 0;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}