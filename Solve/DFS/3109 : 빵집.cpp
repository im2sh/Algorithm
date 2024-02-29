#include <iostream>
#include <queue>

using namespace std;

const int dy[3] = {-1, 0, 1};
const int dx[3] = {1, 1, 1};

int R, C, ret;
bool flag = false;
string BOARD[10001];
int visited[10001][501];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    cin >> R >> C;
    for (int y = 0; y < R; y++) {
        cin >> BOARD[y];
    }
}

void dfs(int y, int x) {
    if (x == C - 1) {
        flag = true;
        ret++;
        return;
    }
    for (int dir = 0; dir < 3; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny >= R || nx < 0 || nx >= C)
            continue;
        if (BOARD[ny][nx] == 'x' || visited[ny][nx])
            continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
        if (flag)
            return;
    }
}

void solve() {
    for (int i = 0; i < R; i++) {
        flag = false;
        dfs(i, 0);
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}