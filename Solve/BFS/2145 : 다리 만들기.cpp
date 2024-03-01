#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
int N;
int BOARD[101][101];
int visited[101][101];
int minDistance = 987654321;
vector<vector<pair<int, int>>> points;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> BOARD[y][x];
        }
    }
}

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> temp;
    q.push({y, x});
    visited[y][x] = 1;
    temp.push_back({y, x});

    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || BOARD[ny][nx] == 0)
                continue;
            temp.push_back({ny, nx});
            q.push({ny, nx});
            visited[ny][nx] = 1;
        }
    }

    points.push_back(temp);
}

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (BOARD[y][x] == 1 && !visited[y][x])
                bfs(y, x);
        }
    }

    for (int i = 0; i < points.size() - 1; i++) {
        for (int j = 0; j < points[i].size(); j++) {
            for (int k = i + 1; k < points.size(); k++) {
                for (int z = 0; z < points[k].size(); z++) {
                    int distance = abs(points[i][j].first - points[k][z].first) +
                                   abs(points[i][j].second - points[k][z].second) - 1;
                    minDistance = min(minDistance, distance);
                }
            }
        }
    }
    cout << minDistance;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}