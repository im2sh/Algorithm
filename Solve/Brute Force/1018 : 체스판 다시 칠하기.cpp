#include <iostream>

using namespace std;
int N, M, cnt, ret = 987654321;

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};
string board[50];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> board[i];
}

int goWB(int x, int y) {
    int sum = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[x + i][y + j] != WB[i][j])
                sum++;
        }
    }
    return sum;
}

int goBW(int x, int y) {
    int sum = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[x + i][y + j] != BW[i][j])
                sum++;
        }
    }
    return sum;
}

void solve() {
    for (int i = 0; i + 8 <= N; i++) {
        for (int j = 0; j + 8 <= M; j++) {
            ret = min(ret, min(goWB(i, j), goBW(i, j)));
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