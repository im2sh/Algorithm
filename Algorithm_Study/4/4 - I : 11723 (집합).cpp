#include <iostream>

using namespace std;

int N, M;
string s;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> M;
}

void solve() {
    int x;
    for (int i = 0; i < M; i++) {
        s.clear();
        cin >> s;
        if (s == "add") {
            cin >> x;
            N |= (1 << x);
        } else if (s == "remove") {
            cin >> x;
            N &= ~(1 << x);
        } else if (s == "check") {
            cin >> x;
            if ((N & (1 << x)) == 0)
                cout << "0" << '\n';
            else
                cout << "1" << '\n';
        } else if (s == "toggle") {
            cin >> x;
            N ^= (1 << x);
        } else if (s == "all")
            N = (1 << 21) - 1;
        else
            N = 0;
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
