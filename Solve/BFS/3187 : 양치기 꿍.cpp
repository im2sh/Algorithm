#include <iostream>
#include <queue>

using namespace std;

constexpr int dy[4] = {-1, 1, 0, 0};
constexpr int dx[4] = {0, 0, -1, 1};

int R, C, sheepRet, wolfRet;
char BOARD[254][254];
bool visited[254][254];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> R >> C;
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            cin >> BOARD[y][x];
        }
    }
}

void go(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;
    int sheep_cnt = 0;
    int wolf_cnt = 0;
    if (BOARD[y][x] == 'v')
        wolf_cnt++;
    else if (BOARD[y][x] == 'k')
        sheep_cnt++;

    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] || BOARD[ny][nx] == '#')
                continue;
            q.push({ny, nx});
            visited[ny][nx] = true;
            if (BOARD[ny][nx] == 'v')
                wolf_cnt++;
            else if (BOARD[ny][nx] == 'k')
                sheep_cnt++;
        }
    }
    if (wolf_cnt >= sheep_cnt)
        wolfRet += wolf_cnt;
    else
        sheepRet += sheep_cnt;
}

void solve() {
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (visited[y][x] || BOARD[y][x] == '#')
                continue;
            go(y, x);
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