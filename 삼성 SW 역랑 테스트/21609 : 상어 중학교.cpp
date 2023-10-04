#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct board {
    int num;
    int cnt;
    int rainbow;
    vector<pair<int, int>> block;
    vector<pair<int, int>> zero;
} BOARD;

BOARD B[21][21];
int visited[21][21];
int N, M, ret, maxCnt, rainbowCnt;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> B[y][x].num;
            B[y][x].cnt = 0;
        }
    }
}

bool exitGame() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (B[y][x].num >= 1 && B[y][x].num != 10)
                return false;
        }
    }
    return true;
}

void findBfs(int y, int x) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> temp;
    vector<pair<int, int>> zero;
    int cnt = 0;
    q.push({y, x});
    temp.push_back({y, x});
    visited[y][x] = 1;

    while (q.size()) {
        cnt++;
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || B[ny][nx].num == -1 || B[ny][nx].num == 10)
                continue;
            if ((B[y][x].num == B[ny][nx].num) || B[ny][nx].num == 0) {
                q.push({ny, nx});
                visited[ny][nx] = 1;
                if (B[ny][nx].num == 0)
                    zero.push_back({ny, nx});
                else
                    temp.push_back({ny, nx});
            }
        }
    }

    B[y][x].cnt = cnt;
    int size = zero.size();
    maxCnt = max(maxCnt, cnt);
    rainbowCnt = max(rainbowCnt, size);
    B[y][x].zero = zero;
    B[y][x].rainbow = size;
    B[y][x].block = temp;
}

void InitZero() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (B[y][x].num == 0)
                visited[y][x] = 0;
        }
    }
};

void findBlock() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (B[y][x].num == 0 || B[y][x].num == -1 || B[y][x].num == 10)
                continue;
            if (!visited[y][x]) {
                InitZero();
                findBfs(y, x);
            }
        }
    }
}

void goRemove(int cy, int cx) {
    vector<pair<int, int>> bNum = B[cy][cx].block;
    vector<pair<int, int>> zNum = B[cy][cx].zero;

    for (int i = 0; i < bNum.size(); i++) {
        B[bNum[i].first][bNum[i].second].num = 10;
        B[bNum[i].first][bNum[i].second].cnt = 0;
    }
    for (int i = 0; i < zNum.size(); i++) {
        B[zNum[i].first][zNum[i].second].num = 10;
    }
    B[cy][cx].zero.clear();
    B[cy][cx].block.clear();
}

void removeBlock() {
    vector<pair<int, int>> temp;
    for (int y = N - 1; y >= 0; y--) {
        for (int x = N - 1; x >= 0; x--) {
            if (B[y][x].cnt == maxCnt) {
                temp.push_back({y, x});
            }
        }
    }

    if (temp.size() == 1) {
        goRemove(temp[0].first, temp[0].second);
    } else {
        for (int i = 0; i < temp.size(); i++) {
            if (B[temp[i].first][temp[i].second].rainbow == rainbowCnt) {
                goRemove(temp[i].first, temp[i].second);
                break;
            }
        }
    }
}

void display() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << B[y][x].num << " ";
        }
        cout << "\n";
    }
}

void rotate() {
    BOARD temp[21][21];
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            temp[x][y] = B[y][N - 1 - x];
        }
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            B[y][x] = temp[y][x];
        }
    }
}

void goDown() {
    for (int y = 0; y < N; y++) {
        int blank = 0;
        for (int x = N - 1; x >= 0; x--) {
            if (B[x][y].num == 10)
                blank++;
            else if (B[x][y].num == -1)
                blank = 0;
            else {
                if (blank != 0) {
                    B[blank + x][y] = B[x][y];
                    B[x][y].num = 10;
                }
            }
        }
    }
}

void InitInfo() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            B[y][x].cnt = 0;
            B[y][x].block.clear();
            B[y][x].zero.clear();
        }
    }
}

void solve() {
    while (1) {
        fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);
        maxCnt = 0;
        rainbowCnt = 0;
        InitInfo();
        findBlock();
        if (maxCnt <= 1)
            break;
        removeBlock();
        display();
        cout << '\n';
        ret += pow(maxCnt, 2);
        goDown();
        rotate();
        goDown();
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << ret;
    return 0;
}

//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int N, M, ret;
//int BOARD[21][21];
//int color[6];
//vector<pair<pair<int, int>, pair<int, int>>> seq;
//int basic;
//int visited[21][21];
//const int dy[4] = {-1, 1, 0, 0};
//const int dx[4] = {0, 0, -1, 1};
//
//void FastIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//}
//
//void Init() {
//    cin >> N >> M;
//    for (int y = 0; y < N; y++) {
//        for (int x = 0; x < N; x++) {
//            cin >> BOARD[y][x];
//        }
//    }
//}
//
////bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
////    if (a.second.first == b.second.first) {
////        return a.second.second < b.second.second;
////    }
////    return a.second.first < b.second.first;
////}
//
//bool cmp(pair<pair<int, int>, pair<int, int>> &a, pair<pair<int, int>, pair<int, int>> &b) {
//    if (a.first.second == b.first.second) {
//        if (a.second.first == b.second.first) {
//            return a.second.second > b.second.second;
//        }
//        return a.second.first > b.second.first;
//    }
//    return a.first.second > b.first.second;
//}
//
//
//void findBlock(int y, int x, int c) {
//    queue<pair<int, int>> q;
//    q.push({y, x});
//    visited[y][x] = 1;
//    int cnt = 1;
//    while (q.size()) {
//        int cy = q.front().first;
//        int cx = q.front().second;
//        q.pop();
//
//        for (int dir = 0; dir < 4; dir++) {
//            int ny = cy + dy[dir];
//            int nx = cx + dx[dir];
//
//            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || BOARD[ny][nx] == -1)
//                continue;
//            if (BOARD[ny][nx] == c || BOARD[ny][nx] == 0) {
//                q.push({ny, nx});
//                visited[ny][nx] = 1;
//                cnt++;
//            }
//        }
//    }
//    if (color[c] < cnt) {
//        color[c] = cnt;
//        for (int i = 0; i < seq.size(); i++) {
//            if (seq[i].first.first == c) {
//                seq[i].first.first = 10000;
//                seq[i].first.second = cnt;
//            }
//        }
//        seq.push_back({{c, cnt},
//                       {y, x}});
//    }
//    basic = max(basic, cnt);
//}
//
////int selectRemove() {
////    vector<int> temp;
////    int choice = 0;
////    for (int i = 1; i <= M; i++) {
////        //cout << color[i] << " " << basic << "\n";
////        if (color[i] == basic) {
////            temp.push_back(i);
////            choice = i;
////            //cout << color[i] << " " << basic << "\n";
////        }
////    }
////    //cout << choice << "\n";
////    //cout << temp.size() << "\n";
////    if (temp.size() == 1)
////        return choice;
//
////    for (int i = 0; i < temp.size(); i++) {
////        for (int y = 0; y < N; y++) {
////            for (int x = 0; x < N; x++) {
////                if (BOARD[y][x] == temp[i]) {
////                    seq.push_back({i, {y, x}});
////                    break;
////                }
////            }
////        }
////    }
////    for (int k = 0; k < seq.size(); k++) {
////        cout << seq[k]. << " ";
////    }
////    sort(seq.begin(), seq.end());
////    return seq[0].first;
////}
//
//void removeBlock() {
//    int cy = seq[0].second.first;
//    int cx = seq[0].second.second;
//    int cnt = 1;
//    //cout << cy << " " << cx << '\n';
//    queue<pair<int, int>> q;
//    q.push({cy, cx});
//    visited[cy][cx] = 1;
//    BOARD[cy][cx] = -2;
//    while (q.size()) {
//        cy = q.front().first;
//        cx = q.front().second;
//        q.pop();
//
//        for (int dir = 0; dir < 4; dir++) {
//            int ny = cy + dy[dir];
//            int nx = cx + dx[dir];
//
//            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || BOARD[ny][nx] == -1)
//                continue;
//            if (BOARD[ny][nx] == seq[0].first.first || BOARD[ny][nx] == 0) {
//                visited[ny][nx] = 1;
//                q.push({ny, nx});
//                BOARD[ny][nx] = -2;
//                cnt++;
//            }
//        }
//    }
//    ret += pow(cnt, 2);
//}
//
//void display() {
//    for (int y = 0; y < N; y++) {
//        for (int x = 0; x < N; x++) {
//            cout << BOARD[y][x] << " ";
//        }
//        cout << "\n";
//    }
//}
//
//void goDown() {
//    for (int i = 0; i < N; i++) {
//        int blank = 0;
//        for (int j = N - 1; j >= 0; j--) {
//            if (BOARD[j][i] == -2)
//                blank++;
//            else if (BOARD[j][i] == -1)
//                blank = 0;
//            else {
//                if (blank != 0) {
//                    BOARD[j + blank][i] = BOARD[j][i];
//                    BOARD[j][i] = -2;
//                }
//            }
//        }
//    }
//}
//
//void goRotate() {
//    int temp[21][21];
//    for (int y = 0; y < N; y++) {
//        for (int x = 0; x < N; x++) {
//            temp[N - 1 - x][y] = BOARD[y][x];
//        }
//    }
//
//    for (int y = 0; y < N; y++) {
//        for (int x = 0; x < N; x++) {
//            BOARD[y][x] = temp[y][x];
//        }
//    }
//}
//
//void solve() {
//    while (true) {
//        basic = 0;
//        seq.clear();
//        for (int y = 0; y < N; y++) {
//            for (int x = 0; x < N; x++) {
//                if (BOARD[y][x] != -1 && BOARD[y][x] != 0 && BOARD[y][x] != -2) {
//                    fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);
//                    findBlock(y, x, BOARD[y][x]);
//                }
//            }
//        }
//        if (!seq.size()) {
//            break;
//        }
//
////        for (int k = 1; k <= M; k++) {
////            cout << color[k] << " ";
////        }
//        fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);
//        //int deleteBlock = selectRemove();
//        sort(seq.begin(), seq.end(), cmp);
////        for (int k = 0; k < seq.size(); k++) {
////            cout << seq[k].second.first << " " << seq[k].second.second << "\n";
////        }
//        //cout << deleteBlock << "\n";
//        removeBlock();
//        goDown();
//        goRotate();
//        display();
//        cout << "\n";
//        goDown();
//        display();
//        cout << "\n";
//        //display();
//    }
//}
//
//int main(void) {
//    FastIO();
//    Init();
//    solve();
//    cout << ret << "\n";
//    return 0;
//}