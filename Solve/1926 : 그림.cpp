#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int BOARD[501][501];
int visited[501][501];
const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1, 0, 0};
vector<int> v;
int ret = 0;
int cnt = 1;

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

void BFS(int y, int x) {
    queue<pair<int, int>> q;
    visited[y][x] = true;
    q.push(make_pair(y, x));

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (BOARD[ny][nx] == 1 && visited[ny][nx] == 0) {
                visited[ny][nx] = 1;
                cnt++;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

bool cmp(int a, int b) {
    return a > b;
}

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (BOARD[y][x] == 1 && visited[y][x] == 0) {
                BFS(y, x);
                v.push_back(cnt);
                ret++;
                cnt = 1;
            }
        }
    }

    sort(v.begin(), v.end(), cmp);

    cout << ret << '\n';

    if (ret == 0) {
        cout << 0 << '\n';
    } else {
        cout << v[0] << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
