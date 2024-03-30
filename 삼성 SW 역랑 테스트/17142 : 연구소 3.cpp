#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct pos {
    int y, x;
} Pos;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int N, M, ret = 987654321;
int zero_cnt = 0;
vector<Pos> virus;
int BOARD[51][51];
int virus_visited[11];
vector<Pos> on_virus;
int visited[51][51];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> BOARD[y][x];
            if (BOARD[y][x] == 2)
                virus.push_back({y, x});
            else if (BOARD[y][x] == 0)
                zero_cnt++;
        }
    }
}

int go() {
    int cnt = 0;
    bool flag = true;
    queue<Pos> q;
    for (int i = 0; i < on_virus.size(); i++) {
        q.push({on_virus[i]});
        visited[on_virus[i].y][on_virus[i].x] = 1;
    }

    while (q.size()) {
        Pos cur = q.front();
        q.pop();
        int cy = cur.y;
        int cx = cur.x;
        if (cnt >= zero_cnt) {
            flag = false;
            break;
        }
        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx])
                continue;
            if (BOARD[ny][nx] == 1)
                continue;
            q.push({ny, nx});
            if (BOARD[ny][nx] == 0)
                cnt++;

            visited[ny][nx] = visited[cy][cx] + 1;
        }
    }

    int temp = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            temp = max(temp, visited[y][x] - 1);
        }
    }
    if (!flag)
        return temp;
    return 987654321;
}

void dfs(int idx, int depth) {
    if (depth == M) {
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        ret = min(ret, go());
        return;
    }

    for (int i = idx; i < virus.size(); i++) {
        if (!virus_visited[i]) {
            virus_visited[i] = 1;
            on_virus.push_back({virus[i]});
            dfs(i, depth + 1);
            on_virus.pop_back();
            virus_visited[i] = 0;
        }
    }
}

void solve() {
    dfs(0, 0);
    if (ret == 987654321)
        cout << "-1";
    else
        cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}