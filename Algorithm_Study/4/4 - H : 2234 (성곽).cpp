#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int N, M;
int mir[51][51];
int visited[51][51];
int cnt;
int ret = 0;
int break_wall = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mir[i][j];
        }
    }
}

int solve(int y, int x) {
    queue<pair<int, int>> q;
    int room_size = 1;
    int cy, cx;
    q.push({y, x});
    visited[y][x] = 1;
    while (q.size()) {
        tie(cy, cx) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (!(mir[cy][cx] & 1 << i)) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if (ny < 0 || ny >= M || nx < 0 || nx >= N || visited[ny][nx])
                    continue;
                room_size++;
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
    return room_size;
}


void display() {
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            cout << visited[y][x] << " ";
        }
        cout << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    for (int y = 0; y < M; ++y) {
        for (int x = 0; x < N; ++x) {
            if (!visited[y][x]) {
                ret = max(ret, solve(y, x));
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
    cout << ret << "\n";

    for (int y = 0; y < M; ++y) {
        for (int x = 0; x < N; ++x) {
            for (int i = 0; i < 4; i++) {
                if (mir[y][x] & 1 << i) {
                    fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
                    mir[y][x] -= (1 << i);
                    break_wall = max(break_wall, solve(y, x));
                    mir[y][x] += (1 << i);
                }
            }
        }
    }

    cout << break_wall << "\n";
    return 0;
}