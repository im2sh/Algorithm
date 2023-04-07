#include <iostream>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int N, M, K;

struct Shark {
    int y, x, dir;
    int pri[4][4];
};
struct Board {
    int sharknum; // Board에 상어 번호
    int t;
    bool sharklive; // 상어 위치
};

Board board[20][20];
Shark shark[401];
int ret = -1;

void display_s() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << board[y][x].sharknum << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void display_t() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << board[y][x].t << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void display_live() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << board[y][x].sharklive << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void go_shark() {
    int sharkKill = M;
    int time = 0;
    bool isChange;
    while (time <= 1000) {
        time++;
        cout << time << "=================" << "\n";
        display_s();
        display_t();
        display_live();
        cout << time << "=================" << "\n";
        for (int s; s < M; s++) {
            Shark ts = shark[s];
            if (ts.y == -1)
                continue;

            int cy = ts.y;
            int cx = ts.x;
            int cd = ts.dir;
            isChange = false;
            for (int d = 0; d < 4; d++) {
                int ny = cy + ts.pri[cd][d];
                int nx = cx + ts.pri[cd][d];

                if (ny < 0 || ny >= N || nx < 0 || ny >= N || board[ny][nx].t != 0)
                    continue;
                isChange = true;


                board[ny][nx].sharknum = s + 1;
                board[ny][nx].sharklive = true;
                board[ny][nx].t = K;

                board[cy][cx].sharklive = false;

                shark[s].y = ny;
                shark[s].x = nx;
                shark[s].dir = ts.pri[cd][d];
            }
            if (!isChange) {
                for (int d = 0; d < 4; d++) {
                    int ny = cy + ts.pri[cd][d];
                    int nx = cy + ts.pri[cd][d];

                    if (ny < 0 || ny >= N || nx < 0 || ny >= N)
                        continue;
                    if (board[ny][nx].sharknum == s + 1) {
                        isChange = true;
                        board[ny][nx].sharknum = s + 1;
                        board[ny][nx].sharklive = true;
                        board[ny][nx].t = K;

                        board[cy][cx].sharklive = false;

                        shark[s].y = ny;
                        shark[s].x = nx;
                        shark[s].dir = ts.pri[cd][d];
                    }
                }
            }
            if (!isChange) {
                shark[s].y = -1;
                sharkKill--;
            }
        }
        if (sharkKill == 1)
            return;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (board[y][x].t > 0)
                    board[y][x].t--;
                if (board[y][x].t == 0)
                    board[y][x].sharknum = 0;
            }
        }
        ret = time;
    }
}

void Init() {
    cin >> N >> M >> K;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> board[y][x].sharknum;
            if (board[y][x].sharknum != 0) {
                int sn = board[y][x].sharknum - 1;
                shark[sn].y = y;
                shark[sn].x = x;

                board[y][x].sharknum = sn + 1;
                board[y][x].t = K + 1;
                board[y][x].sharklive = true;
            }
        }
    }
    int temp;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        shark[i].dir = temp - 1;
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> temp;
                shark[i].pri[j][k] = temp - 1;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Init();
    go_shark();

    cout << ret << "\n";
}


//#include <iostream>
//#include <deque>
//#include <queue>
//
//using namespace std;
//
//struct Pos {
//    int y;
//    int x;
//};
//
//struct Board {
//    Pos pos;
//    bool s; // 냄새
//    int t; // 남은 시간
//    int who;
//    bool now;
//};
//
//struct Shark {
//    Pos pos;
//    int size;
//    int pri_d[4][4];
//    int dir;
//};
//
//const int dy[4] = {-1, 1, 0, 0};
//const int dx[4] = {0, 0, -1, 1};
//
//deque<Shark> shark;
//Board board[20][20];
//int sea[20][20];
//int N, M, K;
//int cnt = 0;
//int tryN = 0;
//
//int selectDir(Shark s) {
//    int dir = s.dir;
//    switch (dir) {
//        case 1:
//            return 0;
//        case 2:
//            return 1;
//        case 3:
//            return 2;
//        case 4:
//            return 3;
//    }
//}
//
//void smell_check() {
//    for (int y = 0; y < N; y++) {
//        for (int x = 0; x < N; x++) {
//            if (board[y][x].s == 1 && board[y][x].now == true) {
//                board[y][x].t--;
//                if (board[y][x].t == 0) {
//                    board[y][x].who = 0;
//                    board[y][x].s = 0;
//                }
//            }
//        }
//    }
//}
//
//void display_s() {
//    for (int y = 0; y < N; y++) {
//        for (int x = 0; x < N; x++) {
//            cout << board[y][x].who << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";
//}
//
//void display_t() {
//    for (int y = 0; y < N; y++) {
//        for (int x = 0; x < N; x++) {
//            cout << board[y][x].t << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";
//}
//
//int aa = 15;
//int temp_c;
//vector<Pos> temp_pos[4];
//vector<int> xxdir;
//int totalN;
//int killShark;
//
//void go_shark() {
//    while (true) {
//        display_s();
//        cout << tryN << "=========================================================\n";
//        display_t();
//        //cout << "=========================================================\n";
//        cnt++;
//        tryN++;
//        if (killShark == M - 1)
//            break;
//        if (tryN > 1000) {
//            tryN = -1;
//            return;
//        }
//        for (int q = 0; q < M; q++) {
//            if (shark[q].size == -1)
//                break;
//            Shark temp = shark[q];
//            board[temp.pos.y][temp.pos.x].now = true;
//            int dir = selectDir(temp);
//
//            temp_c = 0;
//            for (int d = 0; d < 4; d++, temp_c++) {
//                int sdir = temp.pri_d[dir][d];
//                int ny = dy[sdir] + temp.pos.y;
//                int nx = dx[sdir] + temp.pos.x;
//
//                if (ny < 0 || ny >= N || nx < 0 || nx >= N)
//                    continue;
//                if (board[ny][nx].who == 0) {
//                    board[ny][nx].who = temp.size;
//                    board[ny][nx].s = true;
//                    board[ny][nx].t = K;
//                    board[ny][nx].now = false;
//
//                    shark[q].pos.y = ny;
//                    shark[q].pos.x = nx;
//                    shark[q].dir = sdir + 1;
//                    break;
//                } else if (board[ny][nx].who < temp.size) {
//                    shark[q].size = -1;
//                    killShark++;
//                    break;
//                } else {
//                    if (board[ny][nx].who == temp.size) {
//                        temp_pos[temp.size - 1].push_back({ny, nx});
//                        xxdir.push_back(sdir);
//                    }
//
//                    if (temp_c == 3) {
//                        Pos p = temp_pos[temp.size - 1].front();
//                        board[p.y][p.x].t = K;
//                        board[p.y][p.x].now = false;
//
//                        shark[q].pos.y = p.y;
//                        shark[q].pos.x = p.x;
//                        shark[q].dir = xxdir[0];
//                        xxdir.clear();
//                        break;
//                    }
//                }
//            }
//        }
//        smell_check();
//        if (shark.size() == 1)
//            return;
//    }
//}
//
//bool cmp(Shark s1, Shark s2) {
//    return s1.size < s2.size;
//}
//
//void Init() {
//    cin >> N >> M >> K;
//    int temp;
//    Shark tempS;
//
//    for (int y = 0; y < N; y++) {
//        for (int x = 0; x < N; x++) {
//            cin >> temp;
//            board[y][x].pos = {y, x};
//            board[y][x].s = 0;
//            board[y][x].t = 0;
//            board[y][x].who = 0;
//            sea[y][x] = temp;
//            if (sea[y][x] != 0) {
//                tempS.pos = {y, x};
//                tempS.dir = 0;
//                tempS.size = temp;
//                shark.push_back(tempS);
//
//                board[y][x].pos = {y, x};
//                board[y][x].s = true;
//                board[y][x].t = K;
//                board[y][x].who = temp;
//                board[y][x].now = true;
//            }
//        }
//    }
//
//    sort(shark.begin(), shark.end(), cmp);
//
//    for (int i = 0; i < M; i++) {
//        cin >> shark[i].dir;
//    }
//
//    int temp_dir;
//
//    for (int i = 0; i < M; i++) {
//        for (int j = 0; j < 4; j++) {
//            for (int k = 0; k < 4; k++) {
//                cin >> temp_dir;
//                shark[i].pri_d[j][k] = temp_dir - 1;
//            }
//        }
//    }
//}
//
//int main(void) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//
//    Init();
//    go_shark();
//    cout << tryN << "\n";
//}



//#include <iostream>
//#include <deque>
//#include <queue>
//
//using namespace std;
//
//struct Pos {
//    int y;
//    int x;
//};
//
//struct Board {
//    Pos pos;
//    bool s; // 냄새
//    int t; // 남은 시간
//    int who;
//    bool now;
//};
//
//struct Shark {
//    Pos pos;
//    int size;
//    int pri_d[4][4];
//    int dir;
//};
//
//const int dy[4] = {-1, 1, 0, 0};
//const int dx[4] = {0, 0, -1, 1};
//
//deque<Shark> shark;
//Board board[20][20];
//int sea[20][20];
//int N, M, K;
//int cnt = 0;
//int tryN = 0;
//
//int selectDir(Shark s) {
//    int dir = s.dir;
//    switch (dir) {
//        case 1:
//            return 0;
//        case 2:
//            return 1;
//        case 3:
//            return 2;
//        case 4:
//            return 3;
//    }
//}
//
//void smell_check() {
//    for (int y = 0; y < N; y++) {
//        for (int x = 0; x < N; x++) {
//            if (board[y][x].s == 1 && board[y][x].now == true) {
//                board[y][x].t--;
//                if (board[y][x].t == 0) {
//                    board[y][x].who = 0;
//                    board[y][x].s = 0;
//                }
//            }
//        }
//    }
//}
//
//void display() {
//    for (int y = 0; y < N; y++) {
//        for (int x = 0; x < N; x++) {
//            cout << board[y][x].t << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";
//}
//
//int aa = 15;
//int temp_c;
//vector<Pos> temp_pos[4];
//
//void go_shark() {
//    while (true) {
//        display();
//        cnt++;
//        if (shark.size() == 1) {
//            return;
//        } else if (tryN > 1000) {
//            tryN = -1;
//            return;
//        }
//
//        bool flag = true;
//        Shark temp = shark.front();
//        shark.pop_front();
//        board[temp.pos.y][temp.pos.x].now = true;
//        int dir = selectDir(temp);
//
//        temp_c = 0;
//        for (int d = 0; d < 4; d++, temp_c++) {
//            int sdir = temp.pri_d[dir][d];
//            int ny = dy[sdir] + temp.pos.y;
//            int nx = dx[sdir] + temp.pos.x;
//
//            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
//                continue;
//            if (board[ny][nx].who == 0) {
//                board[ny][nx].who = temp.size;
//                board[ny][nx].s = true;
//                board[ny][nx].t = K;
//                board[ny][nx].now = false;
//
//                temp.pos.y = ny;
//                temp.pos.x = nx;
//                temp.dir = sdir + 1;
//                if (cnt == shark.size() + 1) {
//                    smell_check();
//                    cnt = 0;
//                    tryN++;
//                }
//                break;
//            } else if (board[ny][nx].who < temp.size) {
//                if (cnt == shark.size() + 1) {
//                    smell_check();
//                    cnt = 0;
//                    tryN++;
//                }
//                flag = false;
//                break;
//            }
//
//            if (board[ny][nx].who == temp.size) {
//                temp_pos[temp.size - 1].push_back({ny, nx});
//            }
//
//            if (temp_c == 4) {
//                if (cnt == shark.size() + 1) {
//                    tryN++;
//                    smell_check();
//                    cnt = 0;
//                }
//                Pos p = temp_pos[temp.size - 1].front();
//                board[p.y][p.x].t = K;
//                break;
//            }
//        }
//
//        if (flag == true)
//            shark.push_back(temp);
//
//    }
//}
//
//bool cmp(Shark s1, Shark s2) {
//    return s1.size < s2.size;
//}
//
//void Init() {
//    cin >> N >> M >> K;
//    int temp;
//    Shark tempS;
//
//    for (int y = 0; y < N; y++) {
//        for (int x = 0; x < N; x++) {
//            cin >> temp;
//            board[y][x].pos = {y, x};
//            board[y][x].s = 0;
//            board[y][x].t = 0;
//            board[y][x].who = 0;
//            sea[y][x] = temp;
//            if (sea[y][x] != 0) {
//                tempS.pos = {y, x};
//                tempS.dir = 0;
//                tempS.size = temp;
//                shark.push_back(tempS);
//
//                board[y][x].pos = {y, x};
//                board[y][x].s = true;
//                board[y][x].t = K;
//                board[y][x].who = temp;
//                board[y][x].now = true;
//            }
//        }
//    }
//
//    sort(shark.begin(), shark.end(), cmp);
//
//    for (int i = 0; i < M; i++) {
//        cin >> shark[i].dir;
//    }
//
//    int temp_dir;
//
//    for (int i = 0; i < M; i++) {
//        for (int j = 0; j < 4; j++) {
//            for (int k = 0; k < 4; k++) {
//                cin >> temp_dir;
//                shark[i].pri_d[j][k] = temp_dir - 1;
//            }
//        }
//    }
//}
//
//int main(void) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//
//    Init();
//    go_shark();
//    cout << tryN << "\n";
//}
