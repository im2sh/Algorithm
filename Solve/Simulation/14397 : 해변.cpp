#include <iostream>
#include <vector>

using namespace std;

const int posX[6] = {-1, -1, 0, 0, 1, 1};
const int posY_odd[6] = {0, 1, -1, 1, 0, 1};
const int posY_even[6] = {-1, 0, -1, 1, -1, 0};

int N, M, ret;
vector<vector<int>> BOARD;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string temp;
        vector<int> tempV;

        cin >> temp;
        BOARD.push_back(tempV);
        for (auto now: temp) {
            if (now == '.')
                BOARD[i].push_back(1);
            else
                BOARD[i].push_back(0);
        }
    }
}

void solve() {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (BOARD[x][y])
                continue;
            for (int dir = 0; dir < 6; dir++) {
                int tempX = x + posX[dir];
                int tempY;
                if (x % 2 == 0)
                    tempY = y + posY_even[dir];
                else
                    tempY = y + posY_odd[dir];
                if (-1 < tempX && tempX < N && -1 < tempY && tempY < M) {
                    if (BOARD[tempX][tempY])
                        ret++;
                }
            }
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
