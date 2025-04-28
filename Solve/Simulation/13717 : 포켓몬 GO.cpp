#include <iostream>

using namespace std;

int N, ret, maxN = -1;
string S;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    while (N--) {
        string name;
        int A, B;
        cin >> name >> A >> B;

        int cnt = 0;

        while (B - A >= 0) {
            ret++;
            B -= A;
            B += 2;
            cnt++;
        }

        if (maxN < cnt) {
            maxN = cnt;
            S = name;
        }
    }
    cout << ret << '\n' << S;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}