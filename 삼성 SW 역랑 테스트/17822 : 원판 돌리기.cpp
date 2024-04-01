/**
 * 평균값 구하는 거에서 소수점을 이용해서 더하기, 빼기 연산을 진행, 동점인 경우에는 +, - 둘 다 하지 않아야 함
 */

#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;
typedef struct rotateInfo {
    int x, d, k;
} RotateInfo;

int N, M, T;
deque<int> dq[54];
vector<RotateInfo> info;
map<pair<int, int>, int> deletePos;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            dq[i].push_back(temp);
        }
    }

    for (int i = 0; i < T; i++) {
        int x, d, k;
        cin >> x >> d >> k;
        info.push_back({x, d, k});
    }
}

bool rotate(RotateInfo RI) {
    int x = RI.x;
    int d = RI.d;
    int k = RI.k;

    for (int i = 1; i <= N; i++) {
        if (i % x != 0)
            continue;

        if (d == 0) {
            for (int j = 0; j < k; j++) {
                int temp = dq[i].back();
                dq[i].pop_back();
                dq[i].push_front(temp);
            }
        } else {
            for (int j = 0; j < k; j++) {
                int temp = dq[i].front();
                dq[i].pop_front();
                dq[i].push_back(temp);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (dq[i][j] != 0)
                return true;
        }
    }
    return false;
}

void findCircle() {
    deletePos.clear();
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (dq[i][j] == 0)
                continue;
            // 좌우 인접
            if (j == M - 1) {
                if (dq[i][j] == dq[i][0]) {
                    deletePos[{i, j}] = 1;
                    deletePos[{i, 0}] = 1;
                }
            }
                // 상하 인접
            else {
                if (dq[i][j] == dq[i][j + 1]) {
                    deletePos[{i, j}] = 1;
                    deletePos[{i, j + 1}] = 1;
                }
            }

            if (i != N && dq[i][j] == dq[i + 1][j]) {
                deletePos[{i, j}] = 1;
                deletePos[{i + 1, j}] = 1;
            }
        }
    }
}

void deleteCircle() {
    for (auto &it: deletePos) {
        dq[it.first.first][it.first.second] = 0;
    }
}

void adjustCircle() {
    double sum = 0;
    double avg = 0;
    double cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (dq[i][j] == 0)
                continue;
            sum += dq[i][j];
            cnt++;
        }
    }
    avg = sum / cnt;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (dq[i][j] == 0)
                continue;
            if (double(dq[i][j]) > avg)
                dq[i][j]--;
            else if (double(dq[i][j]) < avg)
                dq[i][j]++;
        }
    }
}

int getScore() {
    int ret = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            ret += dq[i][j];
        }
    }
    return ret;
}

void solve() {
    for (int i = 0; i < T; i++) {
        if (rotate(info[i])) {
            findCircle();
            if (deletePos.size())
                deleteCircle();
            else
                adjustCircle();
        }
    }

    cout << getScore();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
