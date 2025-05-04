#include <iostream>

using namespace std;

int N, A, B;
int X, Y;
int m, not_m, sum, semester;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> A >> B;
}

void solve() {
    for (int i = 0; i < 10; i++) {
        cin >> X >> Y;
        for (int j = 0; j < X + Y; j++) {
            if (j == 6)
                break;
            else if (j >= X)
                not_m += 3;
            else
                m += 3;
        }

        semester++;
        sum = m + not_m;

        if ((A + m >= 66) && (B + sum >= 130)) {
            cout << "Nice";
            return;
        }
        if (N + semester == 8) {
            cout << "Nae ga wae";
            return;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}