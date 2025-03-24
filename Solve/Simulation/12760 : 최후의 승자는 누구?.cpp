#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int BOARD[101][101];
int result[101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> BOARD[i][j];
        }
        sort(BOARD[i], BOARD[i] + M);
    }
}

void solve() {
    for (int i = 0; i < M; i++) {
        int temp = 0;
        for (int j = 0; j < N; j++) {
            temp = max(temp, BOARD[j][M - i - 1]);
        }

        for (int j = 0; j < N; j++) {
            if (temp == BOARD[j][M - i - 1]) {
                result[j]++;
            }
        }
    }

    int maxScore = 0;
    for (int i = 0; i < N; i++) {
        maxScore = max(maxScore, result[i]);
    }
    for (int i = 0; i < N; i++) {
        if (maxScore == result[i]) {
            cout << i + 1 << " ";
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}