#include <iostream>

using namespace std;

int N, now;
double arr[4], H, S;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> now;
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }
}

void solve() {
    if (now == 1) {
        H = arr[2];
        S = arr[3];
    } else if (now == 0) {
        H = arr[0];
        S = arr[1];
    }

    for (int i = 0; i < N - 1; i++) {
        double temp1 = H * arr[0] + S * arr[2];
        double temp2 = S * arr[3] + H * arr[1];
        H = temp1;
        S = temp2;
    }

    H *= 1000;
    S *= 1000;

    cout << (int) H << '\n';
    cout << (int) S;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}