#include <iostream>
#include <vector>

using namespace std;

typedef struct dragon {
    int x, y, d, g;
} DRAGON;

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};
int N, ret;
vector<DRAGON> dra;
int BOARD[101][101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int x, y, d, g;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> d >> g;
        dra.push_back({x, y, d, g});
    }
}

void solve() {
    for (auto &it: dra) {
        int curve_size = 0;
        int curve[1024] = {0,};

        BOARD[it.y][it.x] = 1;
        curve[curve_size++] = it.d;
        for (int i = 0; i < it.g; i++) {
            for (int j = curve_size - 1; j >= 0; j--) {
                curve[curve_size++] = (curve[j] + 1) % 4;
            }
        }


        for (int i = 0; i < curve_size; i++) {
            it.y += dy[curve[i]];
            it.x += dx[curve[i]];

            if (it.y < 0 || it.y > 100 || it.x < 0 || it.x > 100)
                continue;
            BOARD[it.y][it.x] = 1;
        }
    }

    for (int y = 0; y <= 100; y++) {
        for (int x = 0; x <= 100; x++) {
            if (BOARD[y][x] && BOARD[y + 1][x] && BOARD[y][x + 1] && BOARD[y + 1][x + 1])
                ret++;
        }
    }
    cout << ret << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}