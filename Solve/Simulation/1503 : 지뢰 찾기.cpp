#include <iostream>

using namespace std;

constexpr int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
constexpr int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N;
char BOARD[1001][1001], ret[1001][1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> BOARD[i];
}

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (BOARD[y][x] != '.') {
                ret[y][x] = '*';
                continue;
            }

            int cnt = 0;

            for (int dir = 0; dir < 8; dir++) {
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N || BOARD[ny][nx] == '.')
                    continue;
                cnt += BOARD[ny][nx] - '0';
            }

            if (cnt >= 10)
                ret[y][x] = 'M';
            else
                ret[y][x] = cnt + '0';
        }
    }
    for (int i = 0; i < N; i++)
        cout << ret[i] << '\n';
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}