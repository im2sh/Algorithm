#include <iostream>
#include <vector>

using namespace std;

const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};

int N, M, R, ret;
int BOARD[101][101];
int ORIGINAL[101][101];
vector<pair<pair<int, int>, int>> attackSeq;
vector<pair<int, int>> defenseSeq;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b;
    char cdir;
    int dir;
    cin >> N >> M >> R;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> BOARD[y][x];
            ORIGINAL[y][x] = BOARD[y][x];
        }
    }
    for (int i = 0; i < R; i++) {
        cin >> a >> b >> cdir;
        if (cdir == 'E')
            dir = 0;
        else if (cdir == 'W')
            dir = 1;
        else if (cdir == 'S')
            dir = 2;
        else if (cdir == 'N')
            dir = 3;
        attackSeq.push_back({{a - 1, b - 1}, dir});
        cin >> a >> b;
        defenseSeq.push_back({a - 1, b - 1});
    }

}

void attack(int y, int x, int dir) {
    int moving = BOARD[y][x];
    int cy = y;
    int cx = x;
    ret++;
    BOARD[y][x] = 0;
    while (true) {
        moving--;
        if (moving == 0)
            break;
        int ny = cy + dy[dir];
        int nx = cx + dx[dir];
        cy = ny;
        cx = nx;
        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            break;

        if (BOARD[ny][nx] > moving) {
            moving = BOARD[ny][nx];
        }
        if (BOARD[ny][nx] != 0)
            ret++;
        BOARD[ny][nx] = 0;
    }
}

void defense(int y, int x) {
    if (BOARD[y][x] != 0)
        ret--;
    BOARD[y][x] = ORIGINAL[y][x];
}

void solve() {
    for (int i = 0; i < R; i++) {
        attack(attackSeq[i].first.first, attackSeq[i].first.second, attackSeq[i].second);
        defense(defenseSeq[i].first, defenseSeq[i].second);
    }
    cout << ret << '\n';
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (BOARD[y][x] == 0)
                cout << "F" << ' ';
            else
                cout << "S" << ' ';
        }
        if(y != N - 1)
            cout << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}