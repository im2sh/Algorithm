#include <iostream>
#include <queue>

using namespace std;

int N, M;
int visited[1004][1004];
int BOARD[1004][1004];
pair<int, int> target;
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> temp;
            if (temp == 2) {
                target.first = y;
                target.second = x;
            }
            BOARD[y][x] = temp;
        }
    }
}

void solve() {
    queue<pair<int, int>> q;
    int y = target.first;
    int x = target.second;
    q.push({y, x});
    visited[y][x] = 1;

    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny == target.first && nx == target.second)
                continue;
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || BOARD[ny][nx] == 0)
                continue;
            visited[ny][nx] = visited[cy][cx] + 1;
            q.push({ny, nx});
        }
    }
}

void display_Result() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (BOARD[y][x] == 0)
                cout << "0" << " ";
            else
                cout << visited[y][x] - 1 << " ";
        }
        cout << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    display_Result();
    return 0;
}