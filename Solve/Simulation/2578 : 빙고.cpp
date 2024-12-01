#include <iostream>
#include <map>

using namespace std;

int ret;
map<int, pair<int, int>> BOARD;
int row[5];
int col[5];
int dia[2];
bool B[6][6];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    fill(&row[0], &row[0] + 5, 5);
    fill(&col[0], &col[0] + 5, 5);
    fill(&dia[0], &dia[0] + 2, 5);
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            cin >> temp;
            BOARD[temp] = {y, x};
        }
    }
}

bool check() {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (row[i] == 0)
            cnt++;
        if (col[i] == 0)
            cnt++;
    }

    for (int i = 0; i < 2; i++) {
        if (dia[i] == 0)
            cnt++;
    }
    if (cnt >= 3)
        return true;
    return false;
}

void solve() {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            ret++;
            int target;
            cin >> target;
            pair<int, int> cur = BOARD[target];
            row[cur.first]--;
            col[cur.second]--;
            if (cur.first == cur.second)
                dia[0]--;
            if (cur.first + cur.second == 4)
                dia[1]--;
            B[cur.first][cur.second] = true;
            if (check()) {
                cout << ret;
                return;
            }
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}