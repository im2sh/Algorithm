#include <iostream>
#include <algorithm>

using namespace std;

constexpr int dy[4] = {-1, -1, -1, 0};
constexpr int dx[4] = {-1, 0, 1, 1,};

int BOARD[21][21];
bool visited[21][21];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    for (int y = 0; y < 19; y++) {
        for (int x = 0; x < 19; x++) {
            cin >> BOARD[y][x];
        }
    }
}

bool check(int y, int x) {
    for (int dir = 0; dir < 4; dir++) {
        int cnt = 0;
        for (int d = 0; d < 2; d++) {
            int i = 1;
            int ddy = dy[dir];
            int ddx = dx[dir];

            if (d == 1) {
                ddy *= -1;
                ddx *= -1;
            }

            while (true) {
                int ny = y + ddy * i;
                int nx = x + ddx * i;
                if (ny < 0 || ny >= 19 || nx < 0 || nx >= 19 || BOARD[y][x] != BOARD[ny][nx])
                    break;
                cnt++;
                i++;
            }
        }
        if (cnt == 4)
            return true;
    }
    return false;
}

void solve() {
    for (int y = 0; y < 19; y++) {
        for (int x = 0; x < 19; x++) {
            if (BOARD[x][y] == 0)
                continue;
            if (check(x, y)) {
                cout << BOARD[x][y] << '\n';
                cout << x + 1 << ' ' << y + 1;
                return;
            }
        }
    }

    cout << 0;
}

int main(void) {
    FastIO();
    Input();
    solve();
    return 0;
}