#include <iostream>

using namespace std;
int TC, a, b, c, d, cx, cy, r, N;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void solve() {
    for (int i = 0; i < TC; i++) {
        cin >> a >> b >> c >> d;
        cin >> N;

        int inDegree = 0;
        int outDegree = 0;

        for (int j = 0; j < N; j++) {
            cin >> cx >> cy >> r;
            if (pow(cx - a, 2) + pow(cy - b, 2) <= r * r) {
                if (pow(cx - c, 2) + pow(cy - d, 2) > r * r) {
                    inDegree++;
                }
            }
            if (pow(cx - c, 2) + pow(cy - d, 2) <= r * r) {
                if (pow(cx - a, 2) + pow(cy - b, 2) > r * r) {
                    outDegree++;
                }
            }
        }
        cout << inDegree + outDegree << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}


