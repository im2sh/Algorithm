#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int N, M;
int idx = 1;
int BOARD[1001][1001];
int visited[1001][1001];
int result[1001][1001];
vector<int> area_visited;
map<pair<int, int>, pair<int, int>> m;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        cin >> temp;
        for (int x = 0; x < M; x++) {
            BOARD[y][x] = temp[x] - '0';
        }
    }
}

void zeroBFS(int y, int x) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> area;
    q.push({y, x});
    visited[y][x] = 1;
    int cnt = 1;

    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        area.push_back({cy, cx});
        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || BOARD[ny][nx])
                continue;

            q.push({ny, nx});
            visited[ny][nx] = 1;
            cnt++;
        }
    }

    for (int i = 0; i < area.size(); i++) {
        m[{area[i].first, area[i].second}] = {idx, cnt};
    }
    idx++;
}

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (!BOARD[y][x] && !visited[y][x])
                zeroBFS(y, x);
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (BOARD[y][x] == 1) {
                area_visited.clear();
                for (int dir = 0; dir < 4; dir++) {
                    bool flag = true;
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];

                    if (ny < 0 || ny >= N || nx < 0 || nx >= M || BOARD[ny][nx])
                        continue;
                    int areaIdx = m[{ny, nx}].first;
                    for (int i = 0; i < area_visited.size(); i++) {
                        if (areaIdx == area_visited[i]) {
                            flag = false;
                        }
                    }
                    if (flag) {
                        result[y][x] += m[{ny, nx}].second;
                        area_visited.push_back(m[{ny, nx}].first);
                    }
                }
                result[y][x] = (result[y][x] + 1) % 10;
            }
        }
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cout << result[y][x];
        }
        if (y != N - 1)
            cout << '\n';
    }

}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}