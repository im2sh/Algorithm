#include <iostream>

using namespace std;

int N, M, ret;
int BOARD[501][501];
int visited[501];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    fill(&BOARD[0][0], &BOARD[0][0] + 501 * 501, 987654321);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        BOARD[a - 1][b - 1] = 1;
    }
}

void solve() {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (BOARD[i][k] == 1 && BOARD[k][j] == 1) {
                    BOARD[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (BOARD[i][j] == 987654321)
                continue;
            if (BOARD[j][i] == 987654321) {
                visited[i]++;
                visited[j]++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (visited[i] == N - 1)
            ret++;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}