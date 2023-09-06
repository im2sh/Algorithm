#include <iostream>
#include <deque>

using namespace std;

int N, K, ret;
deque<pair<bool, int>> BELT;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int x;
    cin >> N >> K;
    for (int i = 0; i < N * 2; i++) {
        cin >> x;
        BELT.push_back({false, x});
    }
}

void display() {
    for (int i = 0; i < 2 * N; i++) {
        cout << BELT[i].second << " ";
    }
    cout << "\n";
}

void solve() {
    int zero = 0;

    while (zero < K) {
//        display();
//        cout << "\n";
        ret++;
        pair<bool, int> temp = BELT.back();
        BELT.pop_back();
        BELT.push_front(temp);

        if (BELT[N - 1].first)
            BELT[N - 1].first = false;

        for (int i = N - 2; i >= 0; i--) {
            int next = i + 1;
            if (!(BELT[i].first) || BELT[next].first || BELT[next].second <= 0)
                continue;
            BELT[next].first = true;
            BELT[next].second--;
            BELT[i].first = false;
        }

        if (BELT[N - 1].first)
            BELT[N - 1].first = false;

        if (!BELT[0].first && BELT[0].second > 0) {
            BELT[0].first = true;
            BELT[0].second--;
        }

        zero = 0;
        for (int i = 0; i < N * 2; i++) {
            if (BELT[i].second == 0)
                zero++;
        }
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
//#include <deque>
//
//using namespace std;
//
//int N, K, ret;
//int BELT[101];
//deque<pair<bool, int>> ROBOT;
//
//void FastIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//}
//
//void Init() {
//    int x, y;
//    cin >> N >> K;
//    for (int i = 0; i < N; i++) {
//        cin >> x >> y;
//        BELT[i * 2] = x;
//        BELT[i * 2 + 1] = y;
//    }
//}
//
//void display() {
//    for (int i = 0; i < 2 * N; i++) {
//        cout << BELT[i] << " ";
//    }
//    cout << "\n";
//}
//
//void solve() {
//    int zero = 0;
//
//    while (zero < K) {
//        display();
//        cout << "\n";
//        ret++;
//        int temp = BELT[2 * N - 1];
//        for (int i = 2 * N - 1; i > 0; i--) {
//            BELT[i] = BELT[i - 1];
//        }
//        BELT[0] = temp;
//
//        int size = ROBOT.size();
//        for (int i = size; i > 0; i--) {
//            ROBOT[i] = ROBOT[i - 1];
//        }
//
//        if (ROBOT.size() == N) {
//            ROBOT.pop_back();
//        }
//
//        size = ROBOT.size();
//        for (int i = size - 1; i > 0; i--) {
//            int next = i + 1;
//            if (BELT[i] > 0 || ROBOT[i])
//                continue;
//            ROBOT[next] = ROBOT[i];
//            BELT[i]--;
//        }
//
//        if (BELT[0] > 0) {
//            ROBOT.push_back(1);
//            BELT[0]--;
//        }
//
//        for (int i = 0; i < N * 2; i++) {
//            if (BELT[i] == 0)
//                zero++;
//        }
//    }
//}
//
//int main(void) {
//    FastIO();
//    Init();
//    solve();
//    cout << ret;
//    return 0;
//}


//#include <iostream>
//
//using namespace std;
//
//int N, K, ret;
//pair<bool, int> BOARD[2][51];
//const int go[2] = {-1, 1};
//
//void FastIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//}
//
//void Init() {
//    int temp = 0;
//    cin >> N >> K;
//
//    for (int x = 0; x < N; x++) {
//        cin >> temp;
//        BOARD[0][x].first = false;
//        BOARD[0][x].second = temp;
//    }
//    for (int x = N - 1; x >= 0; x--) {
//        cin >> temp;
//        BOARD[1][x].first = false;
//        BOARD[1][x].second = temp;
//    }
//}
//
//bool check() {
//    int cnt = 0;
//    for (int y = 0; y < 2; y++) {
//        for (int x = 0; x < N; x++) {
//            if (BOARD[y][x].second <= 0)
//                cnt++;
//        }
//    }
//    if (cnt >= K)
//        return true;
//
//    return false;
//}
//
//void RobotUP() {
//    if (!BOARD[0][0].first && BOARD[0][0].second > 0)
//        BOARD[0][0].first = true;
//}
//
//void display() {
//    for (int y = 0; y < 2; y++) {
//        for (int x = 0; x < N; x++) {
//            cout << BOARD[y][x].second << " ";
//        }
//        cout << "\n";
//    }
//}
//
//void move() {
//    for (int y = 1; y >= 0; y--) {
//        int ny;
//        int nx;
//        if (y == 1) {
//            for (int x = 0; x < N; x++) {
//                if (!BOARD[y][x].first)
//                    continue;
//                display();
//                cout << "\n";
//                if (x == 0) {
//                    ny = 0;
//                    nx = 0;
//                    if (!(BOARD[ny][nx].second) || BOARD[ny][nx].first) {
//                        BOARD[y][x].second--;
//                        continue;
//                    }
//                    BOARD[y][x].first = false;
//                    BOARD[y][x].second--;
//                    BOARD[ny][nx].first = true;
//                } else {
//                    ny = y;
//                    nx = x + go[0];
//                    if (!(BOARD[ny][nx].second) || BOARD[ny][nx].first) {
//                        BOARD[y][x].second--;
//                        continue;
//                    }
//                    BOARD[y][x].first = false;
//                    BOARD[y][x].second--;
//                    BOARD[ny][nx].first = true;
//                }
//            }
//        }
//        if (y == 0) {
//            for (int x = N - 1; x >= 0; x--) {
//                if (!BOARD[y][x].first)
//                    continue;
//                display();
//                cout << "\n";
//                if (x == N - 1) {
//                    ny = 1;
//                    nx = N - 1;
//                    if (!(BOARD[ny][nx].second) || BOARD[ny][nx].first) {
//                        BOARD[y][x].second--;
//                        continue;
//                    }
//                    BOARD[y][x].first = false;
//                    BOARD[y][x].second--;
//                    BOARD[ny][nx].first = true;
//                } else {
//                    ny = y;
//                    nx = x + go[1];
//                    if (!(BOARD[ny][nx].second) || BOARD[ny][nx].first) {
//                        BOARD[y][x].second--;
//                        continue;
//                    }
//                    BOARD[y][x].first = false;
//                    BOARD[y][x].second--;
//                    BOARD[ny][nx].first = true;
//                }
//            }
//        }
//    }
//}
//
//
//void solve() {
//    RobotUP();
//    while (true) {
//        RobotUP();
//        move();
//        if (check()) {
//            break;
//        }
//        ret++;
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