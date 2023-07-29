#include <iostream>

using namespace std;

int R, C, T;
int M[51][51];
int copy_M[51][51];
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};
vector<pair<int, int>> bus;
int ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> R >> C >> T;
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            cin >> M[y][x];
            if (M[y][x] == -1)
                bus.push_back({y, x});

        }
    }
}

void CopyMap() {
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            M[y][x] = copy_M[y][x];
        }
    }
    M[bus[0].first][bus[0].second] = -1;
    M[bus[1].first][bus[0].second] = -1;
}

void spread(int y, int x) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (ny < 0 || ny >= R || nx < 0 || nx >= C || M[ny][nx] == -1)
            continue;
        copy_M[ny][nx] += M[y][x] / 5;
        cnt++;
    }
    copy_M[y][x] += M[y][x] - (M[y][x] / 5) * cnt;
}

void clean() {
    /*
     * 위쪽
    */
    for (int y = bus[0].first - 1; y > 0; y--) {
        copy_M[y][0] = copy_M[y - 1][0];
    }

    for (int x = 0; x < C - 1; x++) {
        copy_M[0][x] = copy_M[0][x + 1];
    }

    for (int y = 0; y < bus[0].first; y++) {
        copy_M[y][C - 1] = copy_M[y + 1][C - 1];
    }

    for (int x = C - 1; x > 0; x--) {
        copy_M[bus[0].first][x] = copy_M[bus[0].first][x - 1];
    }

    copy_M[bus[0].first][bus[0].second + 1] = 0;

    /*
     * 밑쪽
     */

    for (int y = bus[1].first + 1; y < R; y++) {
        copy_M[y][0] = copy_M[y + 1][0];
    }

    for (int x = 0; x < C; x++) {
        copy_M[R - 1][x] = copy_M[R - 1][x + 1];
    }

    for (int y = R - 1; y > bus[1].first; y--) {
        copy_M[y][C - 1] = copy_M[y - 1][C - 1];
    }

    for (int x = C - 1; x > 0; x--) {
        copy_M[bus[1].first][x] = copy_M[bus[1].first][x - 1];
    }

    copy_M[bus[1].first][bus[1].second + 1] = 0;
}

void calcu() {
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (M[y][x] == -1)
                continue;
            ret += M[y][x];
        }
    }
}

void print() {
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            cout << M[y][x] << " ";
        }
        cout << "\n";
    }
}

void InitCopyM() {
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++)
            copy_M[y][x] = 0;
    }
}

void solve() {
    while (T--) {
        InitCopyM();
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                if (!M[y][x] || M[y][x] == -1) {
                    continue;
                }
                spread(y, x);
            }
        }
        clean();
        CopyMap();
        //print();
        cout << "\n";
    }
    calcu();
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << ret << '\n';
    return 0;
}