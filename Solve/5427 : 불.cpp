#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int tc, w, h;

char building[1001][1001];
int visited[1001][1001];
int fire_visited[1001][1001];
vector<pair<int, int>> fireWhere;
pair<int, int> people;
int ret = 0;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> tc;
}

void input() {
    fill(&building[0][0], &building[0][0] + 1001 * 1001, 0);
    fill(&visited[0][0], &visited[0][0] + 1001 * 1001, 0);
    fill(&fire_visited[0][0], &fire_visited[0][0] + 1001 * 1001, 987654321);
    fireWhere.clear();
    ret = 0;
    cin >> w >> h;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> building[y][x];
            if (building[y][x] == '*') {
                fireWhere.push_back({y, x});
                fire_visited[y][x] = 1;
            } else if (building[y][x] == '@')
                people = {y, x};
        }
    }
}

void fire(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    fire_visited[y][x] = 1;

    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= h || nx < 0 || nx >= w || fire_visited[ny][nx] != 987654321 || building[ny][nx] == '#')
                continue;
            fire_visited[ny][nx] = fire_visited[cy][cx] + 1;
            q.push({ny, nx});
        }
    }
}

void move(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        if (cy == 0 || cx == 0 || cy == h - 1 || cx == w - 1) {
            ret = visited[cy][cx];
            break;
        }

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= h || nx < 0 || nx >= w || visited[ny][nx] || building[ny][nx] == '#')
                continue;
            if (visited[cy][cx] + 1 < fire_visited[ny][nx]) {
                visited[ny][nx] = visited[cy][cx] + 1;
                q.push({ny, nx});
            }
        }
    }
}

void display() {
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cout << fire_visited[y][x] << ' ';
        }
        cout << '\n';
    }

    cout << '\n';
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cout << visited[y][x] << ' ';
        }
        cout << '\n';
    }
}

void phase() {
    for (int i = 0; i < fireWhere.size(); i++) {
        fire(fireWhere[i].first, fireWhere[i].second);
    }

    move(people.first, people.second);
    if (ret == 0)
        cout << "IMPOSSIBLE" << '\n';
    else
        cout << ret << '\n';
}

void solve() {
    while (tc--) {
        input();
        phase();
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}