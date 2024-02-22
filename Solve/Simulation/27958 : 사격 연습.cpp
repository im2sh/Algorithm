#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, ret = -1;
int BOARD[9][9];
int COPY_BOARD[9][9];
int original_BOARD[9][9];
vector<vector<int>> seq;
vector<int> temp;
int visited[9];
int bullets[5];

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> BOARD[y][x];
            COPY_BOARD[y][x] = BOARD[y][x];
            original_BOARD[y][x] = BOARD[y][x];
        }
    }

    for (int i = 0; i < K; i++) {
        cin >> bullets[i];
    }
}

void copy_BOARD() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            BOARD[y][x] = COPY_BOARD[y][x];
            original_BOARD[y][x] = COPY_BOARD[y][x];
        }
    }
}

void dfs(int depth) {
    if (depth == K) {
        seq.push_back(temp);
        return;
    }
    for (int i = 0; i < N; i++) {
        temp.push_back(i);
        dfs(depth + 1);
        temp.pop_back();
    }
}

void display() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << BOARD[y][x] << ' ';
        }
        cout << '\n';
    }
}


void solve() {
    dfs(0);
    for (auto &it: seq) {
        copy_BOARD();
        int sum = 0;

        for (int i = 0; i < K; i++) {
            int targetLine = it[i];
            int attack = bullets[i];

            for (int x = 0; x < N; x++) {
                if (BOARD[targetLine][x] == 0)
                    continue;
                int hp = BOARD[targetLine][x] - attack;

                if (BOARD[targetLine][x] >= 10) {
                    sum += BOARD[targetLine][x];
                    BOARD[targetLine][x] = 0;
                } else if (hp > 0) {
                    BOARD[targetLine][x] = hp;
                } else {
                    sum += original_BOARD[targetLine][x];

                    for (int dir = 0; dir < 4; dir++) {
                        int ny = targetLine + dy[dir];
                        int nx = x + dx[dir];

                        if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
                            continue;
                        }

                        if (BOARD[ny][nx] == 0) {
                            BOARD[ny][nx] = original_BOARD[targetLine][x] / 4;
                            original_BOARD[ny][nx] = BOARD[ny][nx];
                        }
                    }
                    BOARD[targetLine][x] = 0;
                }
                break;
            }
        }
        ret = max(ret, sum);
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}