#include <iostream>

using namespace std;

int x, y, r, x2, y2, r2, d, cond1, cond2, num;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> num;
}

void solve() {
    for (int i = 0; i < num; i++) {
        cin >> x >> y >> r >> x2 >> y2 >> r2;
        d = (x - x2) * (x - x2) + (y - y2) * (y - y2);
        cond1 = (r - r2) * (r - r2);
        cond2 = (r + r2) * (r + r2);
        if (d == 0) {
            if (cond1 == 0)
                cout << "-1" << '\n';
            else
                cout << "0" << '\n';
        } else if (d == cond1 || d == cond2)
            cout << "1" << '\n';
        else if (cond1 < d && d < cond2)
            cout << "2" << '\n';
        else
            cout << "0" << '\n';
    }
}

int main() {
    FastIO();
    Init();
    solve();

    return 0;
}