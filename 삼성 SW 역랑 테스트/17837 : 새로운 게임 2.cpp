#include <iostream>
#include <deque>

using namespace std;
/**
 * 벽 또는 파란색 블럭을 2번 연속 만나서 제자리에 있는 경우에는 빨간 블록을 밟아도 순서를 변경하면 안 된다. (twoMoving 변수 확인)
 */
typedef struct horse {
    int idx, y, x, dir;
} Horse;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1, 0, 0};

int N, K, ret;
int BOARD[13][13];
deque<int> info[13][13];
Horse H[11];
bool flag = false;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> BOARD[y][x];
        }
    }
    int a, b, c;
    for (int i = 0; i < K; i++) {
        cin >> a >> b >> c;
        H[i] = {i, a - 1, b - 1, c - 1};
        info[a - 1][b - 1].push_back(i);
    }
}

void move(Horse h) {
    deque<Horse> dq;
    int cy = h.y;
    int cx = h.x;
    int size = info[cy][cx].size();
    bool twoMoving = false;
    for (int i = size; i >= 0; i--) {
        if (info[cy][cx].back() == h.idx) {
            dq.push_front(H[info[cy][cx].back()]);
            info[cy][cx].pop_back();
            break;
        } else {
            dq.push_front(H[info[cy][cx].back()]);
            info[cy][cx].pop_back();
        }
    }

    int ny = h.y + dy[h.dir];
    int nx = h.x + dx[h.dir];

    if (ny < 0 || ny >= N || nx < 0 || nx >= N || BOARD[ny][nx] == 2) {
        if (h.dir == 1)
            h.dir = 0;
        else if (h.dir == 0)
            h.dir = 1;
        else if (h.dir == 2)
            h.dir = 3;
        else
            h.dir = 2;

        ny = ny + dy[h.dir] * 2;
        nx = nx + dx[h.dir] * 2;
        H[dq.front().idx].dir = h.dir;
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || BOARD[ny][nx] == 2) {
            ny = ny - dy[h.dir];
            nx = nx - dx[h.dir];
            twoMoving = true;
        }
        if (BOARD[ny][nx] == 1 && !twoMoving) {
            while (dq.size()) {
                Horse temp = dq.back();
                dq.pop_back();
                H[temp.idx].y = ny;
                H[temp.idx].x = nx;

                info[ny][nx].push_back(temp.idx);
            }
        } else {
            while (dq.size()) {
                Horse temp = dq.front();
                dq.pop_front();
                H[temp.idx].y = ny;
                H[temp.idx].x = nx;

                info[ny][nx].push_back(temp.idx);
            }
        }
    } else if (BOARD[ny][nx] == 0) {
        while (dq.size()) {
            Horse temp = dq.front();
            dq.pop_front();
            H[temp.idx].y = ny;
            H[temp.idx].x = nx;

            info[ny][nx].push_back(temp.idx);
        }
    } else if (BOARD[ny][nx] == 1) {
        while (dq.size()) {
            Horse temp = dq.back();
            dq.pop_back();
            H[temp.idx].y = ny;
            H[temp.idx].x = nx;

            info[ny][nx].push_back(temp.idx);
        }
    }

    if (info[ny][nx].size() >= 4)
        flag = true;
}

void solve() {
    while (true) {
        if (ret > 1000) {
            cout << "-1";
            return;
        }
        for (int i = 0; i < K; i++) {
            move(H[i]);
        }
        ret++;
        if (flag)
            break;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}