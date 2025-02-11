#include <iostream>

using namespace std;

int N, M, K;
int BOARD1[101][101];
int BOARD2[101][101];
int ret[101][101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> BOARD1[i][j];
        }
    }
    cin >> M >> K;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> BOARD2[i][j];
        }
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < M; k++) {
                ret[i][j] += BOARD1[i][k] * BOARD2[k][j];
            }
            cout << ret[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

