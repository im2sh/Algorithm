#include <iostream>
#include <queue>

#define MAXMOVE 200004

using namespace std;

int N, K;
int visited[MAXMOVE];
int map[MAXMOVE];
int cnt[MAXMOVE];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
}

void solve() {
    visited[N] = 1;
    cnt[N] = 1;
    queue<int> q;
    q.push(N);

    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int next: {x + 1, x - 1, x * 2}) {
            if (next < 0 || next >= MAXMOVE)
                continue;
            if (!visited[next]) {
                visited[next] = visited[x] + 1;
                q.push(next);
                cnt[next] += cnt[x];
            } else if (visited[next] == visited[x] + 1) //최단 경로라면 1. 5 -> 10 -> 9 -> 18 -> 17 2. 5 -> 4 -> 8 -> 16 -> 17
                cnt[next] += cnt[x];
        }
    }
    cout << visited[K] - 1 << "\n";
    cout << cnt[K];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}