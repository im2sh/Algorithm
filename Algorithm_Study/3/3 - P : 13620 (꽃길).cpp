#include <iostream>

#define SIZE 11

using namespace std;

int N;
int cost[SIZE][SIZE];
int flower[SIZE][SIZE];
int ret = 987654321;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> cost[y][x];
        }
    }
}

bool checkFlower(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (ny < 0 || ny >= N || nx < 0 || nx >= N || flower[ny][nx])
            return false;
    }
    return true;
}

int setFlower(int y, int x) {
    flower[y][x] = 1;
    int sum = cost[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N || flower[ny][nx])
            return false;
        flower[ny][nx] = 1;
        sum += cost[ny][nx];
    }
    return sum;
}

void eraseFlower(int y, int x) {
    flower[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            continue;
        flower[ny][nx] = 0;
    }
}

void solve(int cnt, int sum) {
    if (cnt == 3) {
        ret = min(ret, sum);
        return;
    }
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (checkFlower(y, x)) {
                solve(cnt + 1, sum + setFlower(y, x));
                eraseFlower(y, x);
            }
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve(0, 0);
    cout << ret << "\n";
    return 0;
}