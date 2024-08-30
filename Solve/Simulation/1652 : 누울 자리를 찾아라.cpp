#include <iostream>

using namespace std;

string S;
int row, col, N, cnt;
char BOARD[101][101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        cnt = 0;
        for (int j = 0; j < temp.size(); j++) {
            BOARD[i][j] = temp[j];
            if (BOARD[i][j] == '.')
                cnt++;
            else {
                if (cnt >= 2)
                    col++;
                cnt = 0;
            }
        }
        if (cnt >= 2)
            col++;
    }

    for (int i = 0; i < N; i++) {
        cnt = 0;
        for (int j = 0; j < N; j++) {
            if (BOARD[j][i] == '.')
                cnt++;
            else {
                if (cnt >= 2)
                    row++;
                cnt = 0;
            }
        }
        if (cnt >= 2)
            row++;
    }

    cout << col << " " << row << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

