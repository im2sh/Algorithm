#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, -1, 0, 1};

int N, M, K, a, b, ret;
int BOARD[41][41];
vector<pair<int, int>> pos;
int B[11][11];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> K;
}

void rotate() {
    int temp = a;
    a = b;
    b = temp;
    int tempB[11][11];
    fill(&tempB[0][0], &tempB[0][0] + 11 * 11, 0);
    for (int y = 0; y < a; y++) {
        for (int x = 0; x < b; x++) {
            tempB[y][x] = B[b - 1 - x][y];
        }
    }
    memcpy(B, tempB, sizeof(B));
    for (int y = 0; y < a; y++) {
        for (int x = 0; x < b; x++) {
            if (B[y][x] == 1)
                pos.push_back({y, x});
        }
    }
}

bool attach() {
    bool canAttach = false;
    vector<pair<int, int>> p;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            int cnt = 0;
            p.clear();
            for (auto &it: pos) {
                int ny = y + it.first;
                int nx = x + it.second;
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || BOARD[ny][nx]) {
                    break;
                }
                p.push_back({ny, nx});
                cnt++;
            }
            if (cnt == pos.size()) {
                canAttach = true;
                break;
            }
        }
        if (canAttach) {
            break;
        }
    }

    if (!canAttach)
        return false;

    for (int i = 0; i < p.size(); i++) {
        BOARD[p[i].first][p[i].second] = 1;
    }
    return true;
}

void solve() {
    for (int i = 0; i < K; i++) {
        pos.clear();
        fill(&B[0][0], &B[0][0] + 11 * 11, 0);
        cin >> a >> b;
        for (int y = 0; y < a; y++) {
            for (int x = 0; x < b; x++) {
                cin >> B[y][x];
            }
        }

        for (int y = 0; y < a; y++) {
            for (int x = 0; x < b; x++) {
                if (B[y][x] == 1) {
                    pos.push_back({y, x});
                }
            }
        }

        for (int direction = 0; direction < 4; direction++) {
            if (attach()) {
                break;
            }
            pos.clear();
            rotate();
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (BOARD[y][x] == 1)
                ret++;
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}