#include <iostream>
#include <queue>

using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1, 0, 0};

int N, M, ret;
int BOARD[101][101];
vector<pair<int, int>> cheese;
int outdoorVisited[101][101];
int cheeseVisited[101][101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> BOARD[y][x];
        }
    }
}

void findOutdoorArea() {
    fill(&outdoorVisited[0][0], &outdoorVisited[0][0] + 101 * 101, 0);
    queue<pair<int, int>> q;
    q.push({0, 0});
    outdoorVisited[0][0] = 1;
    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || outdoorVisited[ny][nx] || BOARD[ny][nx] == 1)
                continue;
            outdoorVisited[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
}

void findCheeseArea() {
    cheese.clear();
    fill(&cheeseVisited[0][0], &cheeseVisited[0][0] + 101 * 101, 0);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (!cheeseVisited[y][x] && BOARD[y][x] == 1) {
                int cnt = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];

                    if (ny < 0 || ny >= N || nx < 0 || nx >= M || BOARD[ny][nx] == 1 || !outdoorVisited[ny][nx])
                        continue;
                    if (BOARD[ny][nx] == 0)
                        cnt++;
                }
                if (cnt >= 2)
                    cheese.push_back({y, x});
            }
        }
    }
}

void deleteCheese() {
    for (int i = 0; i < cheese.size(); i++) {
        int cy = cheese[i].first;
        int cx = cheese[i].second;

        BOARD[cy][cx] = 0;
    }
}

bool check() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (BOARD[y][x] == 1) {
                return true;
            }
        }
    }
    return false;
}


void solve() {
    while (check()) {
        findOutdoorArea();
        findCheeseArea();
        deleteCheese();
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
