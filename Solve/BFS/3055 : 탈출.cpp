#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

int R, C;
string BOARD[51];
pair<int, int> start;
vector<pair<int, int>> water;
int water_visited[51][51];
int visited[51][51];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> temp;
        BOARD[i] = temp;
        for (int j = 0; j < C; j++) {
            if (BOARD[i][j] == 'S')
                start = {i, j};
            else if (BOARD[i][j] == '*')
                water.push_back({i, j});
            if (BOARD[i][j] == 'D')
                water_visited[i][j] = 987654321;
        }
    }
}

void bfs_water() {
    queue<pair<int, int>> q;
    for (int i = 0; i < water.size(); i++) {
        q.push({water[i].first, water[i].second});
        water_visited[water[i].first][water[i].second] = 1;
    }
    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C || BOARD[ny][nx] == 'X' || BOARD[ny][nx] == 'D')
                continue;
            if (water_visited[ny][nx] != 987654321)
                continue;
            q.push({ny, nx});
            water_visited[ny][nx] = water_visited[cy][cx] + 1;
        }
    }
}

void bfs() {
    queue<pair<int, int>> q;
    q.push({start.first, start.second});
    visited[start.first][start.second] = 1;

    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        if (BOARD[cy][cx] == 'D') {
            cout << visited[cy][cx] - 1;
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C || BOARD[ny][nx] == 'X')
                continue;
            if (visited[ny][nx] != 987654321)
                continue;
            if (water_visited[ny][nx] <= visited[cy][cx] + 1)
                continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[cy][cx] + 1;
        }
    }
    cout << "KAKTUS";
}

void solve() {
    fill(&water_visited[0][0], &water_visited[0][0] + 51 * 51, 987654321);
    fill(&visited[0][0], &visited[0][0] + 51 * 51, 987654321);
    bfs_water();
    bfs();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}