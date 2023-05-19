#include <iostream>

using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int R, C;
int ret = -1;
char alpha[21][21];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> R >> C;
    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            cin >> alpha[y][x];
        }
    }
}

void solve(int y, int x, int sum, int cnt) {
    ret = max(ret, cnt);
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (ny < 0 || ny >= R || nx < 0 || nx >= C)
            continue;
        int next = (1 << (alpha[ny][nx] - 65));
        if ((sum & next) == 0)
            solve(ny, nx, sum | next, cnt + 1);
    }
    return;
}

int main(void) {
    FastIO();
    Init();
    solve(0, 0, 1 << (alpha[0][0] - 65), 1);
    cout << ret << "\n";
    return 0;
}