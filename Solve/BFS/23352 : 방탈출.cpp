#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int dy[4] = {0, 0, 1, -1};
constexpr int dx[4] = {-1, 1, 0, 0};

typedef struct pos {
    int y, x, depth;
} Pos;

int N, M;
int BOARD[51][51];
bool visited[51][51];
vector<pair<int, int>> ret;

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

void go(int y, int x) {
    queue<Pos> q;
    int maxNum = 0;
    pair<int, int> longPos;
    q.push({y, x, 0});
    visited[y][x] = true;

    while (q.size()) {
        int cy = q.front().y;
        int cx = q.front().x;
        int depth = q.front().depth;
        q.pop();

        if (maxNum < depth) {
            maxNum = depth;
            longPos = {cy, cx};
        }

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || !BOARD[ny][nx])
                continue;

            q.push({ny, nx, depth + 1});
            visited[ny][nx] = true;
        }
    }

    ret.push_back({maxNum, BOARD[y][x] + BOARD[longPos.first][longPos.second]});
}

bool cmp(pair<int, int> A, pair<int, int> B) {
    if (A.first == B.first) {
        return A.second > B.second;
    }
    return A.first > B.first;
}

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (BOARD[y][x] == 0)
                continue;
            fill(&visited[0][0], &visited[0][0] + 51 * 51, false);
            go(y, x);
        }
    }
    sort(ret.begin(), ret.end(), cmp);
    cout << ret[0].second;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}