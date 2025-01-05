#include <iostream>

using namespace std;

constexpr int dy[4] = {0, 0, 1, -1};
constexpr int dx[4] = {1, -1, 0, 0};

int R, C, wolf, sheep, wolfRet, sheepRet;
string BOARD[251];
bool visited[251][251];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> BOARD[i];
    }
}

void go(int y, int x) {
    visited[y][x] = true;
    if (BOARD[y][x] == 'v')
        wolf++;
    if (BOARD[y][x] == 'o')
        sheep++;
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] || BOARD[y][x] == '#')
            continue;
        go(ny, nx);
    }
}

void solve() {
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (BOARD[y][x] == '#' || visited[y][x])
                continue;
            wolf = 0;
            sheep = 0;
            go(y, x);

            if (wolf >= sheep)
                wolfRet += wolf;
            else
                sheepRet += sheep;
        }
    }
    cout << sheepRet << ' ' << wolfRet;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}