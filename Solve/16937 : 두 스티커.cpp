#include <iostream>

using namespace std;

int h, w, n;
int where = 0;
pair<pair<int, int>, int> sticker[200];
int visited[100];
pair<int, int> stk[2];
int ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> h >> w >> n;
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        sticker[where++] = {{r, c}, i};
        if (r != c) {
            sticker[where++] = {{c, r}, i};
        }
    }
}

void check() {
    if (stk[0].second + stk[1].second <= w && max(stk[0].first, stk[1].first) <= h) {
        ret = max(ret, stk[0].first * stk[0].second + stk[1].first * stk[1].second);
    }
    if (stk[0].second + stk[1].second <= h && max(stk[0].first, stk[1].first) <= w) {
        ret = max(ret, stk[0].first * stk[0].second + stk[1].first * stk[1].second);
    }
}

void go(int idx, int size, int cnt) {
    if (cnt == 2) {
        check();
        return;
    }
    for (int i = idx; i < size; i++) {
        int nextR = sticker[i].first.first;
        int nextC = sticker[i].first.second;
        int stkNum = sticker[i].second;
        if (!visited[stkNum]) {
            visited[stkNum] = 1;
            stk[cnt] = {nextR, nextC};
            go(idx + 1, size, cnt + 1);
            stk[cnt] = {0, 0};
            visited[stkNum] = 0;
        }
    }
}

void solve() {
    go(0, where, 0);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}