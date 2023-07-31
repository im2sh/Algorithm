#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, ret;

typedef struct board {
    int M[21][21];

    void rotate() {
        int copyM[21][21];
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                copyM[y][x] = M[N - x - 1][y];
            }
        }
        memcpy(M, copyM, sizeof(M));
    }

    void up() {
        int copyM[21][21];

        for (int x = 0; x < N; x++) {
            bool flag = false;
            int target = -1;
            for (int y = 0; y < N; y++) {
                if (!M[y][x])
                    continue;

                if (flag && copyM[target][x] == M[y][x]) {
                    copyM[target][x] *= 2;
                    flag = false;
                } else {
                    copyM[++target][x] = M[y][x];
                    flag = true;
                }
            }
            for (++target; target < N; ++target) {
                copyM[target][x] = 0;
            }
        }

        memcpy(M, copyM, sizeof(M));
    }

    void getMax() {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                ret = max(ret, M[y][x]);
            }
        }
    }
} Board;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

Board Init() {
    Board B;
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> B.M[y][x];
        }
    }
    return B;
}

void solve(Board cur, int depth) {
    if (depth == 5) {
        cur.getMax();
        return;
    }

    for (int i = 0; i < 4; i++) {
        Board next = cur;
        next.up();
        solve(next, depth + 1);
        cur.rotate();
    }
}

int main(void) {
    FastIO();
    Board B = Init();
    solve(B, 0);
    cout << ret << "\n";
    return 0;
}