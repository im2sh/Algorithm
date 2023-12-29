#include <iostream>
#include <queue>

using namespace std;

int N, M;
int BOARD[101];
int visited[101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b;
    cin >> N >> M;
    for (int i = 0; i < N + M; i++) {
        cin >> a >> b;
        BOARD[a] = b;
    }
}

void solve() {
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = 1;
    while (q.size()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        if (cur == 100) {
            cout << cnt;
            break;
        }
        q.pop();
        for (int i = 1; i <= 6; i++) {
            int next = cur + i;
            if (next > 100)
                break;
            if (BOARD[next] != 0)
                next = BOARD[next];
            if (!visited[next]) {
                visited[next] = 1;
                q.push({next, cnt + 1});
            }
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}