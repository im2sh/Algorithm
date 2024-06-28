#include <iostream>

using namespace std;

int N, M, B;
int BOARD[504][504];
int mintime = 1e9;
int maxheight = -1;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> BOARD[i][j];
        }
    }
}

void solve() {
    for (int height = 0; height <= 256; height++) {
        int inven = 0;
        int remove = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int cur = BOARD[i][j] - height;
                if (cur < 0)
                    inven -= cur;
                else
                    remove += cur;
            }
        }
        if (remove + B >= inven) {
            int temp = 2 * remove + inven;
            if (mintime >= temp) {
                mintime = temp;
                maxheight = height;
            }
        }
    }
    cout << mintime << " " << maxheight;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}