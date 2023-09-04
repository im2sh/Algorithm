#include <iostream>

using namespace std;

int M, N;
int BOARD[501][501];
int visited[501][501];
int dp[501][501];

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> M >> N;
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            cin >> BOARD[y][x];
        }
    }
}

int solve(int y, int x) {
    if (y == M - 1 && x == N - 1)
        return 1;
    if (visited[y][x])
        return dp[y][x];
    dp[y][x] = 0;
    //cout << y << " " << x << "\n";

    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= M || nx < 0 || nx >= N || BOARD[y][x] <= BOARD[ny][nx])
            continue;
        visited[y][x] = 1;
        dp[y][x] += solve(ny, nx);
    }

    return dp[y][x];
}

int main(void) {
    FastIO();
    Init();
    fill(&dp[0][0], &dp[0][0] + 501 * 501, -1);
    cout << solve(0, 0);
    return 0;
}