#include <iostream>
#include <queue>

using namespace std;

constexpr int dy[4] = {-1, 1, 0, 0};
constexpr int dx[4] = {0, 0, -1, 1};

int R, C, N;
char BOARD[201][201];
queue<pair<int, int>> bomb;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> R >> C >> N;
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            cin >> BOARD[y][x];
            if (BOARD[y][x] == 'O')
                bomb.push({y, x});
        }
    }
}

void installBomb() {
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            BOARD[y][x] = 'O';
        }
    }
}

void goBomb() {
    while (bomb.size()) {
        int cy = bomb.front().first;
        int cx = bomb.front().second;
        bomb.pop();
        BOARD[cy][cx] = '.';
        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                continue;
            BOARD[ny][nx] = '.';
        }
    }

    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (BOARD[y][x] == 'O')
                bomb.push({y, x});
        }
    }
}

void getResult() {
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            cout << BOARD[y][x];
        }
        cout << '\n';
    }
}

void solve() {
    N--;
    while (true) {
        if (N == 0)
            break;
        installBomb();
        N--;
        if (N == 0)
            break;
        goBomb();
        N--;
    }

    getResult();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}