#include <iostream>

#define SIZE 6
using namespace std;

int R, C, K;
int visited[SIZE][SIZE];
char map[SIZE][SIZE];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int ret = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> R >> C >> K;
    string temp;
    for (int y = 0; y < R; ++y) {
        cin >> temp;
        for (int x = 0; x < C; ++x) {
            map[y][x] = temp[x];
        }
    }
    visited[R - 1][0] = 1;
}

void display() {
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            cout << visited[y][x] << " ";
        }
        cout << "\n";
    }
}

void solve(int y, int x) {
    if (y == 0 && x == C - 1 && visited[y][x] == K) {
        ret++;
    }

    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (ny < 0 || ny >= R || nx < 0 || nx >= C || map[ny][nx] == 'T' || visited[ny][nx])
            continue;
        visited[ny][nx] = visited[y][x] + 1;
        solve(ny, nx);
        visited[ny][nx] = 0;
    }
}

int main(void) {
    FastIO();
    Init();
    solve(R - 1, 0);
    cout << ret << "\n";
    return 0;
}