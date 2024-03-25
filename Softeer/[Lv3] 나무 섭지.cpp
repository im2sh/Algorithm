#include<iostream>
#include <queue>

using namespace std;

int N, M;
string BOARD[1001];
queue<pair<int, int>> q;
pair<int, int> startPos;
pair<int, int> endPos;
vector<pair<int, int>> ghost;
int ghost_visited[1001][1001];
int visited[1001][1001];

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
    for (int i = 0; i < N; i++) {
        cin >> temp;
        BOARD[i] = temp;
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (BOARD[y][x] == 'N')
                startPos = {y, x};
            else if (BOARD[y][x] == 'D')
                endPos = {y, x};
            else if (BOARD[y][x] == 'G')
                ghost.push_back({y, x});
        }
    }
}

void Gbfs() {
    queue<pair<int, int>> q;
    for (int i = 0; i < ghost.size(); i++) {
        q.push({ghost[i].first, ghost[i].second});
        ghost_visited[ghost[i].first][ghost[i].second] = 1;
    }

    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (ghost_visited[ny][nx] > ghost_visited[cy][cx] + 1) {
                q.push({ny, nx});
                ghost_visited[ny][nx] = ghost_visited[cy][cx] + 1;
            }
        }
    }
}

bool bfs() {
    queue<pair<int, int>> q;
    q.push({startPos.first, startPos.second});
    visited[startPos.first][startPos.second] = 1;

    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        if (cy == endPos.first && cx == endPos.second)
            return true;
        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || BOARD[ny][nx] == '#')
                continue;
            if (visited[cy][cx] + 1 > ghost_visited[ny][nx])
                continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[cy][cx] + 1;
        }
    }
    return false;
}

void solve() {
    fill(&ghost_visited[0][0], &ghost_visited[0][0] + 1001 * 1001, 987654321);
    Gbfs();

    if (bfs())
        cout << "Yes";
    else
        cout << "No";
}

int main(int argc, char **argv) {
    FastIO();
    Init();
    solve();
    return 0;
}