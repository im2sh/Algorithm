#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int dy[4] = {-1, 1, 0, 0};
constexpr int dx[4] = {0, 0, -1, 1};


int N = 12;
int M = 6;
int ret;
char BOARD[13][7];
bool visited[13][7];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> BOARD[y][x];
        }
    }
}

bool bomb() {
    fill(&visited[0][0], &visited[0][0] + 13 * 7, false);
    bool flag = false;
    vector<pair<int, int>> bombList;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (BOARD[y][x] == '.')
                continue;
            visited[y][x] = true;
            bombList.clear();
            queue<pair<int, int>> q;
            q.push({y, x});
            bombList.push_back({y, x});

            while (q.size()) {
                int cy = q.front().first;
                int cx = q.front().second;
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int ny = cy + dy[dir];
                    int nx = cx + dx[dir];

                    if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || BOARD[ny][nx] != BOARD[y][x])
                        continue;
                    q.push({ny, nx});
                    bombList.push_back({ny, nx});
                    visited[ny][nx] = true;
                }
            }

            if (bombList.size() >= 4) {
                flag = true;
                for (int i = 0; i < bombList.size(); i++) {
                    int cy = bombList[i].first;
                    int cx = bombList[i].second;
                    BOARD[cy][cx] = '.';
                }
            }
        }
    }
    return flag;
}

void goDown() {
    queue<char> q;
    for (int x = 0; x < M; x++) {
        for (int y = N - 1; y >= 0; y--) {
            if (BOARD[y][x] == '.')
                continue;
            q.push(BOARD[y][x]);
            BOARD[y][x] = '.';
        }
        for (int y = N - 1; y >= 0; y--) {
            if (q.size() == 0)
                break;
            BOARD[y][x] = q.front();
            q.pop();
        }
    }
}

void solve() {
    while (true) {
        if (!bomb())
            break;
        goDown();
        ret++;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}