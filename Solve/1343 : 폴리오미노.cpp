#include <iostream>

using namespace std;

string board, ret;
int cnt;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> board;
    board += ' ';

}

void solve() {
    for (int i = 0; i < board.size() - 1; i++) {
        if (board[i] == 'X')
            cnt++;
        if (board[i] == '.') {
            ret += ".";
            if (cnt % 2 != 0)
                break;
            else
                cnt = 0;
        }

        if (cnt == 2 && board[i + 1] != 'X') {
            ret += "BB";
            cnt = 0;
        } else if (cnt == 4) {
            ret += "AAAA";
            cnt = 0;
        }
    }

    if (cnt % 2 == 1)
        cout << -1;
    else
        cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
