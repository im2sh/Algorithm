#include <iostream>
#include <queue>

using namespace std;

int N, M, ret;
int BOARD[21][21];
int color[6];
vector<pair<pair<int, int>, pair<int, int>>> seq;
int basic;
int visited[21][21];
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

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
}

//bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
//    if (a.second.first == b.second.first) {
//        return a.second.second < b.second.second;
//    }
//    return a.second.first < b.second.first;
//}

bool cmp(pair<pair<int, int>, pair<int, int>> &a, pair<pair<int, int>, pair<int, int>> &b) {
    if (a.first.second == b.first.second) {
        if (a.second.first == b.second.first) {
            return a.second.second > b.second.second;
        }
        return a.second.first > b.second.first;
    }
    return a.first.second > b.first.second;
}


void findBlock(int y, int x, int c) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;
    int cnt = 1;
    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || BOARD[ny][nx] == -1)
                continue;
            if (BOARD[ny][nx] == c || BOARD[ny][nx] == 0) {
                q.push({ny, nx});
                visited[ny][nx] = 1;
                cnt++;
            }
        }
    }
    if (color[c] < cnt) {
        color[c] = cnt;
        for (int i = 0; i < seq.size(); i++) {
            if (seq[i].first.first == c) {
                seq[i].first.first = 10000;
                seq[i].first.second = cnt;
            }
        }
        seq.push_back({{c, cnt},
                       {y, x}});
    }
    basic = max(basic, cnt);
}

//int selectRemove() {
//    vector<int> temp;
//    int choice = 0;
//    for (int i = 1; i <= M; i++) {
//        //cout << color[i] << " " << basic << "\n";
//        if (color[i] == basic) {
//            temp.push_back(i);
//            choice = i;
//            //cout << color[i] << " " << basic << "\n";
//        }
//    }
//    //cout << choice << "\n";
//    //cout << temp.size() << "\n";
//    if (temp.size() == 1)
//        return choice;

//    for (int i = 0; i < temp.size(); i++) {
//        for (int y = 0; y < N; y++) {
//            for (int x = 0; x < N; x++) {
//                if (BOARD[y][x] == temp[i]) {
//                    seq.push_back({i, {y, x}});
//                    break;
//                }
//            }
//        }
//    }
//    for (int k = 0; k < seq.size(); k++) {
//        cout << seq[k]. << " ";
//    }
//    sort(seq.begin(), seq.end());
//    return seq[0].first;
//}

void removeBlock() {
    int cy = seq[0].second.first;
    int cx = seq[0].second.second;
    int cnt = 1;
    //cout << cy << " " << cx << '\n';
    queue<pair<int, int>> q;
    q.push({cy, cx});
    visited[cy][cx] = 1;
    BOARD[cy][cx] = -2;
    while (q.size()) {
        cy = q.front().first;
        cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || BOARD[ny][nx] == -1)
                continue;
            if (BOARD[ny][nx] == seq[0].first.first || BOARD[ny][nx] == 0) {
                visited[ny][nx] = 1;
                q.push({ny, nx});
                BOARD[ny][nx] = -2;
                cnt++;
            }
        }
    }
    ret += pow(cnt, 2);
}

void display() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << BOARD[y][x] << " ";
        }
        cout << "\n";
    }
}

void goDown() {
    for (int i = 0; i < N; i++) {
        int blank = 0;
        for (int j = N - 1; j >= 0; j--) {
            if (BOARD[j][i] == -2)
                blank++;
            else if (BOARD[j][i] == -1)
                blank = 0;
            else {
                if (blank != 0) {
                    BOARD[j + blank][i] = BOARD[j][i];
                    BOARD[j][i] = -2;
                }
            }
        }
    }
}

void goRotate() {
    int temp[21][21];
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            temp[N - 1 - x][y] = BOARD[y][x];
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            BOARD[y][x] = temp[y][x];
        }
    }
}

void solve() {
    while (true) {
        basic = 0;
        seq.clear();
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (BOARD[y][x] != -1 && BOARD[y][x] != 0 && BOARD[y][x] != -2) {
                    fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);
                    findBlock(y, x, BOARD[y][x]);
                }
            }
        }
        if (!seq.size()) {
            break;
        }

//        for (int k = 1; k <= M; k++) {
//            cout << color[k] << " ";
//        }
        fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);
        //int deleteBlock = selectRemove();
        sort(seq.begin(), seq.end(), cmp);
//        for (int k = 0; k < seq.size(); k++) {
//            cout << seq[k].second.first << " " << seq[k].second.second << "\n";
//        }
        //cout << deleteBlock << "\n";
        removeBlock();
        goDown();
        goRotate();
        display();
        cout << "\n";
        goDown();
        display();
        cout << "\n";
        //display();
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << ret << "\n";
    return 0;
}