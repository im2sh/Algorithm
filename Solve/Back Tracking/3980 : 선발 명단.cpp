#include <iostream>
#include <algorithm>

using namespace std;

int TC, ret = 0;
bool visited[11];
int BOARD[11][11];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    ret = 0;
    for (int y = 0; y < 11; y++) {
        for (int x = 0; x < 11; x++) {
            cin >> BOARD[y][x];
        }
    }
}

void go(int row, int sum) {
    if (row == 11) {
        ret = max(ret, sum);
        return;
    }

    for (int x = 0; x < 11; x++) {
        if (!visited[x] && BOARD[row][x]) {
            visited[x] = true;
            go(row + 1, sum + BOARD[row][x]);
            visited[x] = false;
        }
    }
}

void solve() {
    while (TC--) {
        Input();
        go(0, 0);
        cout << ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}