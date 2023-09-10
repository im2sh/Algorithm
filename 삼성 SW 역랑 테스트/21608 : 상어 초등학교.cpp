#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int N, ret;
pair<int, vector<int>> info[401];
int school[401][401];
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b, c, d, e;
    cin >> N;
    for (int i = 0; i < pow(N, 2); i++) {
        cin >> a >> b >> c >> d >> e;
        info[i].first = a;
        info[i].second.push_back(b);
        info[i].second.push_back(c);
        info[i].second.push_back(d);
        info[i].second.push_back(e);
    }
}

void go(pair<int, vector<int>> p) {
    int temp[401][401] = {1,};
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            temp[y][x] = 1;
        }
    }
    int target = p.first;
    int maxN = 0;

    for (int i = 0; i < 4; i++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                for (int dir = 0; dir < 4; dir++) {
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                        continue;
                    if (p.second[i] == school[ny][nx]) {
                        temp[y][x] += 5;
                    }
                }
            }
        }
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (school[y][x] != 0) {
                temp[y][x] = 0;
                continue;
            }
            for (int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N || school[ny][nx]) {
                    continue;
                }

                temp[y][x]++;
            }
        }
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            maxN = max(maxN, temp[y][x]);
        }
    }

    bool flag = false;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (temp[y][x] == maxN && school[y][x] == 0) {
                school[y][x] = target;
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
}

int cal(vector<int> t, int cy, int cx) {
    int cnt = 0;
    for (int i = 0; i < t.size(); i++) {
        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;
            if (school[ny][nx] == t[i]) {
                cnt++;
            }
        }
    }
    switch (cnt) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 10;
        case 3:
            return 100;
        case 4:
            return 1000;
    }
    return 0;
}

void solve() {
    for (int i = 0; i < pow(N, 2); i++) {
        go(info[i]);
    }

    for (int i = 0; i < pow(N, 2); i++) {
        int t = info[i].first;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (t == school[y][x]) {
                    ret += cal(info[i].second, y, x);
                }
            }
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << ret << "\n";
    return 0;
}