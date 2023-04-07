#include <iostream>
#include <queue>

using namespace std;

int N, M, K;

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct Pos {
    int y, x;
};

struct Info {
    int m, s, v;
};

struct Ball {
    Pos pos;
    Info In;
};

vector<int> map[54][54];
vector<Ball> fireBall;
int ret = 0;
int dir1[4] = {0, 2, 4, 6};
int dir2[4] = {1, 3, 5, 7};

void magic() {
    vector<Ball> tempBall;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x].size() == 0) {
                continue;
            } else if (map[y][x].size() == 1) {
                int num = map[y][x][0];
                tempBall.push_back(fireBall[num]);
                continue;
            }
            bool odd = false, even = false;
            int ms = 0; // 질량 합
            int ss = 0; // 속도 합
            for (int i = 0; i < map[y][x].size(); i++) {
                int num = map[y][x][i];
                Ball temp = fireBall[num];
                int m = temp.In.m;
                int s = temp.In.s;
                int v = temp.In.v;

                ms += m;
                ss += s;

                if (v % 2 == 0) {
                    odd = true;
                } else if (v % 2 == 1) {
                    even = true;
                }
            }

            ms /= 5;
            if (ms == 0)
                continue;
            ss /= map[y][x].size();

            for (int i = 0; i < 4; i++) {
                if (!odd || !even)
                    tempBall.push_back({y, x, ms, ss, dir1[i]});
                else
                    tempBall.push_back({y, x, ms, ss, dir2[i]});
            }
        }
    }
    fireBall = tempBall;
}

void move() {
    vector<int> tempMap[54][54];
    for (int i = 0; i < fireBall.size(); i++) {
        int cd = fireBall[i].In.v; // 방향
        int cy = fireBall[i].pos.y;
        int cx = fireBall[i].pos.x;
        int cs = fireBall[i].In.s % N; // 속도

        int ny = (cy + dy[cd] * cs + N) % N;
        int nx = (cx + dx[cd] * cs + N) % N;

        fireBall[i].pos.y = ny;
        fireBall[i].pos.x = nx;
        tempMap[ny][nx].push_back(i);
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            map[y][x] = tempMap[y][x];
        }
    }
}

void Init() {
    cin >> N >> M >> K;
    int a, b, c, d, e;
    Ball temp;

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c >> d >> e;
        temp.pos.y = a - 1;
        temp.pos.x = b - 1;
        temp.In.m = c;
        temp.In.s = d;
        temp.In.v = e;
        fireBall.push_back(temp);
        map[temp.pos.y][temp.pos.x].push_back(i);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Init();
    for (int i = 0; i < K; i++) {
        move();
        magic();
    }

    for (int i = 0; i < fireBall.size(); i++) {
        ret += fireBall[i].In.m;
    }
    cout << ret << "\n";
    return 0;
}


//#include <iostream>
//#include <queue>
//#include <cmath>
//
//using namespace std;
//
//int N, M, K;
//
//int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
//int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//
//struct Pos {
//    int y, x;
//};
//
//struct Info {
//    int m, s, v;
//};
//
//struct Ball {
//    Pos pos;
//    Info In;
//};
//
//queue<Ball> fireball;
//queue<Ball> realBall;
//vector<Ball> magicBall;
//vector<int> ballDir;
//int map[54][54] = {0,};
//int tdir[4];
//
//void display_d() {
//    for (int y = 0; y < N; y++) {
//        for (int x = 0; x < N; x++) {
//            cout << map[y][x] << " ";
//        }
//        cout << "\n";
//    }
//};
//
//void magic(int y, int x) {
//    int sm = 0, sp = 0;
//    int odd = 0;
//    int even = 0;
//    bool oe = false; // 짝수 홀수
//    int fs = fireball.size();
//    for (int i = 0; i < fs; i++) {
//        Ball temp = fireball.front();
//        int fby = temp.pos.y;
//        int fbx = temp.pos.x;
//        fireball.pop();
//        if (fby == y && fbx == x) {
//            magicBall.push_back(temp);
//        } else {
//            fireball.push(temp);
//        }
//    }
//    ballDir.clear();
//    int size = magicBall.size();
//    for (int i = 0; i < size; i++) {
//        Ball tm = magicBall.back();
//        magicBall.pop_back();
//        sm += tm.In.m;
//        sp += tm.In.s;
//        ballDir.push_back(tm.In.v);
//    }
//
//    sm /= 5;
//    if (sm == 0) {
//        map[y][x] = 0;
//        return;
//    }
//    sp /= size;
//
//    for (int i = 0; i < ballDir.size(); i++) {
//        if (ballDir[i] % 2 == 0)
//            even++;
//        else
//            odd++;
//    }
//    if (even == ballDir.size() || odd == ballDir.size()) {
//        oe = true;
//    }
//
//    if (oe == true) {
//        tdir[0] = 0;
//        tdir[1] = 2;
//        tdir[2] = 4;
//        tdir[3] = 6;
//    } else {
//        tdir[0] = 1;
//        tdir[1] = 3;
//        tdir[2] = 5;
//        tdir[3] = 7;
//    }
//    for (int i = 0; i < 4; i++) {
//        Ball trb;
//        trb.pos.y = y;
//        trb.pos.x = x;
//        trb.In.m = sm;
//        trb.In.s = sp;
//        trb.In.v = tdir[i];
//        realBall.push(trb);
//    }
//}
//
//// move가 한 번 끝나면  realball -> fireball
//
//void move() {
//    int fs = fireball.size();
//    for (int i = 0; i < fs; i++) {
//        Ball temp = fireball.front();
//        fireball.pop();
//
//        int y = temp.pos.y;
//        int x = temp.pos.x;
//
//        int speed = temp.In.s % N;
//        int dir = temp.In.v;
//        int ny = (temp.pos.y + dy[dir] * speed + N) % N;
//        int nx = (temp.pos.x + dx[dir] * speed + N) % N;
//
//        temp.pos.y = ny;
//        temp.pos.x = nx;
//        fireball.push(temp);
//        if (map[y][x] > 0)
//            map[y][x]--;
//        map[ny][nx]++;
//    }
//    for (int y = 0; y < N; y++) {
//        for (int x = 0; x < N; x++) {
//            if (map[y][x] == 0 || map[y][x] == 1) {
//                continue;
//            }
//            if (map[y][x] >= 2) {
//                magic(y, x);
//            }
//        }
//    }
//}
//
//void Init() {
//    cin >> N >> M >> K;
//    int a, b, c, d, e;
//    Ball temp;
//
//    for (int i = 0; i < M; i++) {
//        cin >> a >> b >> c >> d >> e;
//        temp.pos.y = a - 1;
//        temp.pos.x = b - 1;
//        temp.In.m = c;
//        temp.In.s = d;
//        temp.In.v = e;
//        map[temp.pos.y][temp.pos.x]++;
//        fireball.push(temp);
//    }
//}
//
//int main(void) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    int rs;
//    Init();
//    for (int i = 0; i < K; i++) {
//        move();
//        rs = realBall.size();
//        for (int j = 0; j < rs; j++) {
//            fireball.push(realBall.front());
//            realBall.pop();
//        }
//    }
//
//    int ret = 0;
//    int fbs = fireball.size();
//    for (int i = 0; i < fbs; i++) {
//        ret += fireball.front().In.m;
//        fireball.pop();
//    }
//    cout << ret << "\n";
//    return 0;
//}