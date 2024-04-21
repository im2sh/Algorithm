#include <iostream>
#include <vector>

using namespace std;

int BOARD[9][9];
vector<pair<int, int>> pos;
bool flag = false;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> BOARD[i][j];
            if (BOARD[i][j] == 0)
                pos.push_back({i, j});
        }
    }
}

bool check(int y, int x, int val) {
    for (int i = 0; i < 9; i++) {
        if (BOARD[y][i] == val)
            return false;
        if (BOARD[i][x] == val)
            return false;
    }
    int startY = y / 3;
    int startX = x / 3;
    startY *= 3;
    startX *= 3;
    for (int i = startY; i < startY + 3; i++) {
        for (int j = startX; j < startX + 3; j++) {
            if (BOARD[i][j] == val)
                return false;
        }
    }
    return true;
}

void go(int idx) {
    if (idx == pos.size()) {
        for (int y = 0; y < 9; y++) {
            for (int x = 0; x < 9; x++) {
                cout << BOARD[y][x] << ' ';
            }
            cout << '\n';
        }
        flag = true;
    }
    if (flag)
        return;
    int cy = pos[idx].first;
    int cx = pos[idx].second;
    for (int i = 1; i <= 9; i++) {
        if (check(cy, cx, i)) {
            BOARD[cy][cx] = i;
            go(idx + 1);
            BOARD[cy][cx] = 0;
        }
    }

}

void solve() {
    go(0);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}