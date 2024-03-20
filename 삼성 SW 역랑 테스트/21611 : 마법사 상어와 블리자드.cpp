#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <cstring>

using namespace std;

typedef struct pos {
    int y;
    int x;
} Pos;

const int magicDy[4] = {-1, 1, 0, 0};
const int magicDx[4] = {0, 0, -1, 1};

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

int N, M, ret;
int BOARD[51][51];
vector<pair<int, int>> magic;
Pos center;
deque<int> dq;
int ret_cnt[3];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> BOARD[y][x];
        }
    }
    center = {(N + 1) / 2 - 1, (N + 1) / 2 - 1};
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        magic.push_back({a - 1, b});
    }
}

void goMagic(pair<int, int> m) {
    for (int i = 1; i <= m.second; i++) {
        int ny = center.y + magicDy[m.first] * i;
        int nx = center.x + magicDx[m.first] * i;
        BOARD[ny][nx] = 0;
    }
}

void display() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << BOARD[y][x] << ' ';
        }
        cout << '\n';
    }
}

void trans() {
    //dq.push_back({center.y, center.x});
    queue<pair<int, int>> q;
    q.push({center.y, center.x});
    int dir = 0;
    int dir_cnt = 1; // 몇 번 갈 수 있는지
    int cnt = 0;

    while (q.size()) {
        if (cnt == 2) {
            dir_cnt++;
            cnt = 0;
        }
        for (int i = 0; i < dir_cnt; i++) {
            int cy = q.front().first;
            int cx = q.front().second;
            if (cy == 0 && cx == 0)
                return;
            q.pop();

            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            q.push({ny, nx});
            if (BOARD[ny][nx] != 0)
                dq.push_back(BOARD[ny][nx]);
        }

        dir = (dir + 1) % 4;
        cnt++;
    }
}

void deleteBall() {
    while (true) {
        int cnt = 0;
        int idx = 1;
        vector<int> temp;
        bool flag = false;
        for (int i = 1; i < dq.size(); i++) {
            idx++;
            if (dq[i] == dq[i - 1])
                cnt++;
            else {
                if (cnt >= 3) {
                    flag = true;
                    int tt = dq[i - 1];
                    ret_cnt[tt - 1] += cnt + 1;
                    for (int j = i - cnt - 1; j < i; j++) {
                        dq[j] = 0;
                    }
                }
                cnt = 0;
            }
        }
        if (cnt >= 3) {
            flag = true;
            int tt = dq[idx - 1];
            ret_cnt[tt - 1] += cnt + 1;
            for (int j = idx - cnt - 1; j < idx; j++) {
                dq[j] = 0;
            }
        }

        for (int i = 0; i < dq.size(); i++) {
            if (dq[i] == 0)
                continue;
            temp.push_back(dq[i]);
        }

        dq.clear();
        for (int i = 0; i < temp.size(); i++)
            dq.push_back(temp[i]);

        if (!flag)
            break;
    }
}

void changeBall() {
    int cnt = 0;
    vector<int> temp;
    for (int i = 1; i < dq.size(); i++) {
        if (temp.size() >= N * N)
            break;
        if (dq[i] == dq[i - 1])
            cnt++;
        else {
            temp.push_back(cnt + 1);
            temp.push_back(dq[i - 1]);
            cnt = 0;
        }
    }
    if (cnt > 0) {
        temp.push_back(cnt + 1);
        temp.push_back(dq[dq.size() - 1]);
    } else if (dq.size()) {
        temp.push_back(1);
        temp.push_back(dq[dq.size() - 1]);
    }
    dq.clear();
    for (int i = 0; i < temp.size(); i++) {
        if (i >= (N * N) - 1)
            break;
        dq.push_back(temp[i]);
    }
}

void transOriginal() {
    fill(&BOARD[0][0], &BOARD[0][0] + 51 * 51, 0);
    queue<pair<int, int>> q;
    q.push({center.y, center.x});
    int dir = 0;
    int dir_cnt = 1; // 몇 번 갈 수 있는지
    int cnt = 0;

    while (q.size()) {
        if (cnt == 2) {
            dir_cnt++;
            cnt = 0;
        }
        for (int i = 0; i < dir_cnt; i++) {
            int cy = q.front().first;
            int cx = q.front().second;
            if (cy == 0 && cx == 0)
                return;
            q.pop();

            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            q.push({ny, nx});
            if (dq.size()) {
                BOARD[ny][nx] = dq.front();
                dq.pop_front();
            } else {
                BOARD[ny][nx] = 0;
            }
        }

        dir = (dir + 1) % 4;
        cnt++;
    }
}

void displayDq() {
    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << ' ';
    }
}

void solve() {
    for (int i = 0; i < M; i++) {
        goMagic(magic[i]);
        trans();
        deleteBall();
        changeBall();
        transOriginal();
    }
    for (int i = 0; i < 3; i++) {
        ret += (i + 1) * ret_cnt[i];
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}