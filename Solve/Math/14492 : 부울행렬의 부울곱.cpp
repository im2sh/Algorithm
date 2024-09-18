#include <iostream>

using namespace std;

int N, ret;
int A[304][304], B[304][304];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> A[y][x];
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> B[y][x];
        }
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool flag = false;
            for (int k = 0; k < N; k++) {
                flag |= (A[i][k] && B[k][j]);
                if (flag) {
                    ret++;
                    break;
                }
            }
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}