#include <iostream>
#include <cstring>

using namespace std;

constexpr int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
constexpr int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int R, C;
string BOARD[100];
int visited[100][100];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> R >> C;
    for (int y = 0; y < R; y++) {
        cin >> BOARD[y];
    }
    memset(visited, 0, sizeof(visited));
}

void solve() {
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (BOARD[y][x] == '*') {
                for (int k = 0; k < 8; k++) {
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                        continue;
                    visited[ny][nx] += 1;
                }
            }
        }
    }


    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (BOARD[y][x] == '*')
                cout << '*';
            else
                cout << visited[y][x];
        }
        cout << '\n';
    }
}

int main(void) {
    FastIO();
    while (true) {
        Init();
        if (R == 0 && C == 0)
            break;
        solve();
    }
    return 0;
}