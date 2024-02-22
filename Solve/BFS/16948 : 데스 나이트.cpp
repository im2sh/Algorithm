#include <iostream>
#include <queue>

using namespace std;

const int dy[6] = {-1, 1, -2, 2, -1, 1};
const int dx[6] = {-2, -2, 0, 0, 2, 2};

int N;
int r1, c1, r2, c2;
int path[201][201];
int visited[201][201];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> r1 >> c1 >> r2 >> c2;
}

void BFS(int y, int x) {
    queue<pair<int, int>> q;
    path[y][x] = 0;
    visited[y][x] = 1;
    q.push(make_pair(y, x));

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny > N || nx > N)
                continue;
            if (!visited[ny][nx]) {
                visited[ny][nx] = 1;
                path[ny][nx] = path[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

void solve() {
    BFS(c1, r1);

    if (path[c2][r2] == 0)
        cout << -1;
    else
        cout << path[c2][r2];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
