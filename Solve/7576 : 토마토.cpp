#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int M, N;
vector<pair<int, int>> start;
int tomato[1004][1004];
int visited[1004][1004];
int ret = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            cin >> tomato[y][x];
            if (tomato[y][x] == 1) {
                start.push_back(make_pair(y, x));
            }
        }
    }
}

bool check() {
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            if (tomato[y][x] == 0)
                return false;
        }
    }
    return true;
}

void display() {
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            cout << visited[y][x] << " ";
        }
        cout << "\n";
    }
}

void solve() {
    queue<pair<int, int>> q;
    for (int i = 0; i < start.size(); i++) {
        int y = start[i].first;
        int x = start[i].second;
        q.push({y, x});
        visited[y][x] = 1;
    }
    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= M || nx < 0 || nx >= N || tomato[ny][nx] == -1 || visited[ny][nx])
                continue;
            visited[ny][nx] = visited[cy][cx] + 1;
            tomato[ny][nx] = 1;
            q.push({ny, nx});
            ret = max(ret, visited[ny][nx]);
        }
    }
}

int main(void) {
    FastIO();
    Init();
    if (start.size() == 0) {
        cout << "-1";
        return 0;
    }
    solve();
    if (ret == 0)
        cout << "0" << "\n";
    else if (check())
        cout << ret - 1 << "\n";
    else
        cout << "-1" << "\n";

    return 0;
}
