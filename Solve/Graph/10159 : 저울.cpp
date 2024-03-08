#include <iostream>

using namespace std;

int N, M;
int BOARD[101][101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b;
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        BOARD[a][b] = 1;
    }
}

void solve() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (BOARD[i][k] == 1 && BOARD[k][j] == 1) {
                    BOARD[i][j] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j)
                continue;
            if (BOARD[i][j] == BOARD[j][i]) {
                sum++;
            }
        }
        cout << sum << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}