#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M, D, ret, oneGameResult;
int cnt = 0;
int BOARD[16][16];
int TEMP_BOARD[16][16];
vector<pair<int, int>> archer;
int visited[16];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> D;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> BOARD[y][x];
            TEMP_BOARD[y][x] = BOARD[y][x];
        }
    }
}

void batch_archer() {
    archer.clear();
    for (int i = 0; i < M; i++) {
        if (visited[i]) {
            archer.push_back({N, i});
        }
    }
}

void display() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cout << BOARD[y][x] << ' ';
        }
        cout << '\n';
    }
}

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if (a.first == b.first)
        return a.second.second < b.second.second;
    return a.first < b.first;
}

void attack() {
    vector<pair<int, pair<int, int>>> enemy;
    vector<pair<int, int>> oneLineEnemy;
    for (int i = 0; i < archer.size(); i++) {
        int ay = archer[i].first;
        int ax = archer[i].second;
        enemy.clear();

        for (int y = N - 1; y >= N - D; y--) {
            for (int x = 0; x < M; x++) {
                if (BOARD[y][x] == 1) {
                    int dist = abs(ay - y) + abs(ax - x);
                    if (dist <= D) {
                        enemy.push_back({dist, {y, x}});
                    }
                }
            }
        }
        if (enemy.size()) {
            sort(enemy.begin(), enemy.end(), cmp);
            oneLineEnemy.push_back({enemy[0].second.first, enemy[0].second.second});
        }
    }
    for (int i = 0; i < oneLineEnemy.size(); i++) {
        if (BOARD[oneLineEnemy[i].first][oneLineEnemy[i].second] == 0)
            continue;
        oneGameResult++;
        BOARD[oneLineEnemy[i].first][oneLineEnemy[i].second] = 0;
    }
}

void goDown() {
    for (int y = N - 1; y > 0; y--) {
        for (int x = 0; x < M; x++) {
            BOARD[y][x] = BOARD[y - 1][x];
        }
    }
    for (int x = 0; x < M; x++) {
        BOARD[0][x] = 0;
    }
}

bool allClear() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (BOARD[y][x] == 1)
                return false;
        }
    }
    return true;
}

void goOneGame() {
    batch_archer();
    oneGameResult = 0;
    int tryCount = N;
    while (tryCount--) {
        if (allClear()) {
            break;
        }
        attack();
        goDown();
    }
}

void redo_board() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            BOARD[y][x] = TEMP_BOARD[y][x];
        }
    }
}

void select_archer(int idx, int depth) {
    if (depth == 3) {
        redo_board();
        goOneGame();
        ret = max(ret, oneGameResult);
        return;
    }

    for (int i = idx; i < M; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            select_archer(i, depth + 1);
            visited[i] = 0;
        }
    }
}

void solve() {
    select_archer(0, 0);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}