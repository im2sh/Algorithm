#include <iostream>
#include <algorithm>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int N, ret = -1;
string BOARD[51];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        BOARD[i] = temp;
    }
}

int check() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int temp1 = 1;
        int temp2 = 1;
        for (int j = 1; j < N; j++) {
            if (BOARD[i][j] == BOARD[i][j - 1]) {
                temp1++;
                cnt = max(cnt, temp1);
            } else {
                cnt = max(cnt, temp1);
                temp1 = 1;
            }

            if (BOARD[j][i] == BOARD[j - 1][i]) {
                temp2++;
                cnt = max(cnt, temp2);
            } else {
                cnt = max(cnt, temp2);
                temp2 = 1;
            }
        }
    }
    return cnt;
}

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < BOARD[y].size(); x++) {
            for (int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                    continue;

                char temp = BOARD[ny][nx];
                BOARD[ny][nx] = BOARD[y][x];
                BOARD[y][x] = temp;

                ret = max(ret, check());

                temp = BOARD[ny][nx];
                BOARD[ny][nx] = BOARD[y][x];
                BOARD[y][x] = temp;
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