#include <iostream>

using namespace std;

int N, M, ret = 1;
int BOARD[51][51];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.size(); j++)
            BOARD[i][j] = temp[j] - '0';
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int cnt = 0;
            for (int k = 1;; k++) {
                if ((j + k) >= M || (i + k) >= N)
                    break;
                if (BOARD[i][j] == BOARD[i][j + k] && BOARD[i][j] == BOARD[i + k][j] &&
                    BOARD[i][j] == BOARD[i + k][j + k])
                    if (cnt < k)
                        cnt = k;
            }
            if (cnt + 1 > ret)
                ret = cnt + 1;
        }
    }
    cout << ret * ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
