#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct pos {
    int y, x;
} Pos;
int N, M, H, ret;
vector<Pos> milk;
Pos start;
bool visited[11];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> H;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int temp;
            cin >> temp;
            if (temp == 1)
                start = {y, x};
            else if (temp == 2)
                milk.push_back({y, x});
        }
    }
}

void go(int y, int x, int hp, int cnt) {
    if (abs(start.y - y) + abs(start.x - x) <= hp) {
        ret = max(ret, cnt);
    }

    if (hp <= 0)
        return;

    for (int i = 0; i < milk.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            int diff = (abs(y - milk[i].y) + abs(x - milk[i].x));
            if (hp >= diff)
                go(milk[i].y, milk[i].x, hp - diff + H, cnt + 1);
            visited[i] = false;
        }
    }
}

void solve() {
    go(start.y, start.x, M, 0);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}