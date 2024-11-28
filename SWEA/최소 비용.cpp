#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct Pos {
    int y, x, cnt;
};

struct cmp {
    bool operator()(Pos A, Pos B) {
        return A.cnt < B.cnt;
    }
};

constexpr int dy[4] = {0, 0, -1, 1};
constexpr int dx[4] = {-1, 1, 0, 0};

int TC, N, ret;
int BOARD[101][101];
int dist[101][101];


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    fill(&dist[0][0], &dist[0][0] + 101 * 101, 987654321);
    fill(&BOARD[0][0], &BOARD[0][0] + 101 * 101, 0);
    ret = 0;
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> BOARD[y][x];
        }
    }
}

void go() {
    priority_queue<Pos, vector<Pos>, cmp> pq;
    pq.push({0, 0, 0});

    while (pq.size()) {
        int cy = pq.top().y;
        int cx = pq.top().x;
        int now = pq.top().cnt;
        pq.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;

            if (BOARD[cy][cx] < BOARD[ny][nx]) {
                int diff = BOARD[ny][nx] - BOARD[cy][cx];
                if (dist[ny][nx] > now + diff + 1) {
                    dist[ny][nx] = now + diff + 1;
                    pq.push({ny, nx, now + diff + 1});
                }
            } else {
                if (dist[ny][nx] > now + 1) {
                    dist[ny][nx] = now + 1;
                    pq.push({ny, nx, now + 1});
                }
            }
        }
    }
    ret = dist[N - 1][N - 1];
}

void solve() {
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        Init();
        go();

        cout << '#' << i << ' ' << ret << '\n';
    }
}

int main(void) {
    FastIO();
    solve();
    return 0;
}