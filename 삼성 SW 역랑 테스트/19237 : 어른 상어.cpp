/*
 * 1. 이동 후에 방향 바뀌는 것
 * 2. 다른 상어를 잡아 먹는 것 (1만 잡아 먹을 수 있는 것이 아님.)
 * 3. 같은 위치에 여러 상어가 존재할 때
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct shark {
    int y;
    int x;
    int dir;
    bool isAlive;
    int prior[4][4];
} Shark;

typedef struct board {
    vector<pair<int, int>> smell; // 냄새 뿌린 상어의 idx, 몇 번째 Turn
} Board;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int N, M, K;
Board BOARD[21][21];
Shark SHARK[404];
vector<pair<int, Shark>> MovingShark;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N >> M >> K;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> temp;
            if (temp != 0) {
                SHARK[temp - 1].y = y;
                SHARK[temp - 1].x = x;
                SHARK[temp - 1].isAlive = true;
                BOARD[y][x].smell.push_back({temp - 1, K});
            }
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> temp;
        SHARK[i].dir = temp - 1;
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> temp;
                SHARK[i].prior[j][k] = temp - 1;
            }
        }
    }
}

bool oneSharkLive() {
    for (int i = 1; i < M; i++) {
        if (SHARK[i].isAlive)
            return false;
    }
    return true;
}

void sharkMove() {
    for (int i = 0; i < M; i++) {
        Shark S = SHARK[i];
        if (!S.isAlive)
            continue;

        int cy = S.y;
        int cx = S.x;
        int canMoveCnt = 0;
        pair<int, int> nextDir;
        int tempDir = 0;
        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;

            if (BOARD[ny][nx].smell.empty()) {
                canMoveCnt++;
                nextDir = {ny, nx};
                tempDir = dir;
            }
        }
        if (canMoveCnt == 1) { //아무 냄새 없는 곳이 1곳인 경우
            int ny = nextDir.first;
            int nx = nextDir.second;
            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;

            SHARK[i].y = ny;
            SHARK[i].x = nx;
            SHARK[i].dir = tempDir;
            MovingShark.push_back({i, SHARK[i]});
        } else if (canMoveCnt > 1) { //갈 수 있는 곳이 여러 곳인 경우
            int sd = S.dir;
            bool canMove = false;
            for (int dir = 0; dir < 4; dir++) {
                int ny = cy + dy[S.prior[sd][dir]];
                int nx = cx + dx[S.prior[sd][dir]];

                if (canMove)
                    break;

                if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                    continue;
                if (BOARD[ny][nx].smell.size())
                    continue;

                canMove = true;
                SHARK[i].y = ny;
                SHARK[i].x = nx;
                SHARK[i].dir = S.prior[sd][dir];
                MovingShark.push_back({i, SHARK[i]});
            }

        } else { // canMoveCnt가 0인 경우
            int sd = S.dir;
            bool canMove = false;
            for (int dir = 0; dir < 4; dir++) {
                int ny = cy + dy[S.prior[sd][dir]];
                int nx = cx + dx[S.prior[sd][dir]];
                if (canMove)
                    break;
                if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                    continue;

                for (int j = 0; j < BOARD[ny][nx].smell.size(); j++) {
                    if (i == BOARD[ny][nx].smell[j].first) {
                        canMove = true;
                        SHARK[i].y = ny;
                        SHARK[i].x = nx;
                        SHARK[i].dir = S.prior[sd][dir];
                        BOARD[ny][nx].smell[j].first = i;
                        BOARD[ny][nx].smell[j].second = K + 1;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < MovingShark.size(); i++) {
        int idx = MovingShark[i].first;
        int cy = MovingShark[i].second.y;
        int cx = MovingShark[i].second.x;
        BOARD[cy][cx].smell.push_back({idx, K + 1});
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

void oneTurnEnd() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (!BOARD[y][x].smell.empty()) {
                for (int i = 0; i < BOARD[y][x].smell.size(); i++) {
                    BOARD[y][x].smell[i].second--;
                }

                sort(BOARD[y][x].smell.begin(), BOARD[y][x].smell.end(), cmp);
                while (true) {
                    int lastN = BOARD[y][x].smell.back().second;
                    if (lastN > 0 || BOARD[y][x].smell.empty())
                        break;
                    BOARD[y][x].smell.pop_back();
                }
            }
        }
    }

    for (int i = 0; i < M; i++) {
        if (!SHARK[i].isAlive)
            continue;
        for (int j = i + 1; j < M; j++) {
            if (SHARK[i].y == SHARK[j].y && SHARK[i].x == SHARK[j].x) {
                SHARK[j].y = 99999;
                SHARK[j].x = 99999;
                SHARK[j].isAlive = false;
            }
        }
    }
}

void display() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (BOARD[y][x].smell.size()) {
                cout << "{" << BOARD[y][x].smell[0].first << "," << BOARD[y][x].smell[0].second << "}" << ' ';
            } else {
                cout << "{0, 0}" << ' ';
            }
        }
        cout << '\n';
    }
    cout << '\n';
}

void solve() {
    int ret = 0;
    while (!oneSharkLive()) {
        if (ret >= 1000) {
            cout << "-1";
            return;
        }
        sharkMove();
        oneTurnEnd();
        MovingShark.clear();
        ret++;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}