#include <iostream>
#include <queue>

using namespace std;

int N;
int A, B;
string BOARD[101];

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int visited[101][101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        BOARD[i] = temp;
    }
}

void go(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;
    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || BOARD[cy][cx] != BOARD[ny][nx] || visited[ny][nx])
                continue;
            q.push({ny, nx});
            visited[ny][nx] = 1;
        }
    }

}

void TransRG() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (BOARD[y][x] == 'G')
                BOARD[y][x] = 'R';
        }
    }
}

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (!visited[y][x]) {
                go(y, x);
                A++;
            }
        }
    }
    fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
    TransRG();
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (!visited[y][x]) {
                go(y, x);
                B++;
            }
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << A << " " << B;
    return 0;
}