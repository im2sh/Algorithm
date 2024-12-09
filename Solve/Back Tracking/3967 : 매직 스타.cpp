#include <iostream>
#include <vector>

using namespace std;

char BOARD[6][10];
string ret;
bool flag = false;
vector<pair<int, int>> XPos;

bool visited[12];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 9; x++) {
            cin >> BOARD[y][x];
            if (BOARD[y][x] == 'x')
                XPos.push_back({y, x});
            else if (BOARD[y][x] != '.')
                visited[BOARD[y][x] - 'A'] = true;
        }
    }
}

bool check() {
    int sum = BOARD[0][4] + BOARD[1][5] + BOARD[2][6] + BOARD[3][7] + 4;
    sum -= (65 * 4);
    if (sum != 26)
        return false;

    sum = BOARD[3][1] + BOARD[3][3] + BOARD[3][5] + BOARD[3][7] + 4;
    sum -= (65 * 4);
    if (sum != 26)
        return false;

    sum = BOARD[0][4] + BOARD[1][3] + BOARD[2][2] + BOARD[3][1] + 4;
    sum -= (65 * 4);
    if (sum != 26)
        return false;

    sum = BOARD[1][1] + BOARD[1][3] + BOARD[1][5] + BOARD[1][7] + 4;
    sum -= (65 * 4);
    if (sum != 26)
        return false;

    sum = BOARD[1][1] + BOARD[2][2] + BOARD[3][3] + BOARD[4][4] + 4;
    sum -= (65 * 4);
    if (sum != 26)
        return false;

    sum = BOARD[1][7] + BOARD[2][6] + BOARD[3][5] + BOARD[4][4] + 4;
    sum -= (65 * 4);
    if (sum != 26)
        return false;

    flag = true;
    return true;
}

void go(int depth, int idx) {
    if (flag)
        return;
    if (depth == XPos.size()) {
        if (check()) {
            for (int y = 0; y < 5; y++) {
                for (int x = 0; x < 9; x++) {
                    cout << BOARD[y][x];
                }
                if (y != 4)
                    cout << '\n';
            }
        }
        return;
    }

    for (int i = 0; i < 13; i++) {
        if (!visited[i]) {
            visited[i] = true;
            BOARD[XPos[idx].first][XPos[idx].second] = (i + 'A');
            idx++;
            go(depth + 1, idx);
            BOARD[XPos[idx].first][XPos[idx].second] = '.';
            idx--;
            visited[i] = false;
        }
    }
}

void solve() {
    go(0, 0);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}