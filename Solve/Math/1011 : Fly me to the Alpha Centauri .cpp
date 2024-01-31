#include <iostream>
#include <cmath>

using namespace std;
int TC, x, y;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void solve() {
    while (TC--) {
        cin >> x >> y;

        int dist = y - x;
        double midN = double(sqrt(dist));
        int basic = floor(midN);

        if (basic == midN)
            cout << (midN * 2) - 1 << '\n';
        else if (basic + 0.5 > midN)
            cout << (basic * 2) << '\n';
        else if (basic + 0.5 < midN)
            cout << (basic * 2) + 1 << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}