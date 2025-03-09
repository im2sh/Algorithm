#include <iostream>
#include <queue>

using namespace std;

constexpr int dy[4] = {-1, 1, 0, 0};
constexpr int dx[4] = {0, 0, -1, 1};

typedef struct pos {
    int y, x, num, cnt;
} Pos;

typedef struct cmp {
    bool operator()(Pos a, Pos b) {
        if (a.cnt == b.cnt)
            return a.num > b.num;
        return a.cnt > b.cnt;
    }
};

int N, K, S, X, Y;
int BOARD[204][204];
bool visited[204][204];
priority_queue<Pos, vector<Pos>, cmp> pq;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> BOARD[i][j];
            if (BOARD[i][j] != 0) {
                pq.push({i, j, BOARD[i][j], 0});
                visited[i][j] = true;
            }
        }
    }
    cin >> S >> Y >> X;
}

void solve() {
    while (pq.size()) {
        Pos now = pq.top();
        pq.pop();

        if (now.cnt > S - 1) {
            break;
        }

        for (int dir = 0; dir < 4; dir++) {
            int ny = now.y + dy[dir];
            int nx = now.x + dx[dir];

            if (ny < 1 || ny >= (N + 1) || nx < 1 || nx >= (N + 1) || visited[ny][nx])
                continue;
            visited[ny][nx] = true;
            BOARD[ny][nx] = BOARD[now.y][now.x];
            pq.push({ny, nx, BOARD[now.y][now.x], now.cnt + 1});
        }
    }
    cout << BOARD[Y][X];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}