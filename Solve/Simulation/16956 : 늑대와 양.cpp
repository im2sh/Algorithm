#include <iostream>
#include <queue>

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int N, M;
string BOARD[504];
queue<pair<int, int>> q;
bool flag = true;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> BOARD[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (BOARD[i][j] == 'W') {
                q.push(make_pair(i, j));
            }
        }
    }
}

void solve() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (BOARD[nx][ny] == 'S') {
                flag = false;
                break;
            }
            if (BOARD[nx][ny] == '.')
                BOARD[nx][ny] = 'D';
        }
    }
    if (!flag) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
        for (int i = 0; i < N; i++) {
            cout << BOARD[i] << "\n";
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}