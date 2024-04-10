#include <iostream>
#include <queue>

using namespace std;

typedef struct pos {
    int s, t, ret;
} Pos;

int TC, S, T;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

int bfs() {
    queue<Pos> q;
    q.push({S, T, 0});

    while (q.size()) {
        int cur = q.front().s;
        int end = q.front().t;
        int cnt = q.front().ret;
        q.pop();
        if (cur > end)
            continue;
        if (cur == end) {
            return cnt;
        }

        q.push({cur * 2, end + 3, cnt + 1});
        q.push({cur + 1, end, cnt + 1});
    }
}

void solve() {
    while (TC--) {
        cin >> S >> T;
        cout << bfs() << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}