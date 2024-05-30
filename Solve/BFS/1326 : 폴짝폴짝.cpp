#include <iostream>
#include <queue>

using namespace std;

int dist[10001];
int cnt[10001];
bool visited[10001];

int N;
int S, E;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> dist[i];
    }
    cin >> S >> E;
}

void go() {
    queue<int> q;
    q.push(S);
    visited[S] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == E)
            return;

        for (int i = cur + dist[cur]; i <= N; i += dist[cur]) {
            if (visited[i])
                continue;
            visited[i] = true;
            cnt[i] = cnt[cur] + 1;
            q.push(i);
        }

        for (int i = cur - dist[cur]; i >= 1; i -= dist[cur]) {
            if (visited[i])
                continue;
            visited[i] = true;
            cnt[i] = cnt[cur] + 1;
            q.push(i);
        }
    }
}

void solve() {
    go();
    if (cnt[E] == 0)
        cout << -1;
    else
        cout << cnt[E];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
