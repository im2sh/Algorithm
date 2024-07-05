#include <iostream>

using namespace std;
int w, h, p, q, t;
bool pb = true, qb = true;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> w >> h;
    cin >> p >> q;
    cin >> t;
}

void solve() {
    int pt = t % (2 * w);
    int qt = t % (2 * h);

    while (pt--) {
        if (p == w) {
            pb = false;
        } else if (p == 0) {
            pb = true;
        }
        if (pb)
            p++;
        else
            p--;
    }
    while (qt--) {
        if (q == h) {
            qb = false;
        } else if (q == 0) {
            qb = true;
        }
        if (qb)
            q++;
        else
            q--;
    }
    cout << p << " " << q;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
