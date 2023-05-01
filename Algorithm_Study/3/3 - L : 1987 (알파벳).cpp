#include <iostream>
#include <algorithm>

#define MAX_SIZE 21

using namespace std;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

char alpha[MAX_SIZE][MAX_SIZE];
int R, C;
int visited[26];
int ret = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> R >> C;
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            cin >> alpha[y][x];
        }
    }
    visited[alpha[0][0] - 65] = 1;
}

void solve(int y, int x, int cnt) {
    ret = max(ret, cnt);

    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (ny < 0 || ny >= R || nx < 0 || nx >= C)
            continue;
        int next = alpha[ny][nx] - 65;

        if (!visited[next]) {
            visited[next] = 1;
            solve(ny, nx, cnt + 1);
            visited[next] = 0;
        }
    }

}

int main(void) {
    FastIO();
    Init();
    solve(0, 0, 1);
    cout << ret;
    return 0;
}
