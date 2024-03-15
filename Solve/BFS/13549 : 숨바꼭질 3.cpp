#include <iostream>
#include <queue>

using namespace std;
int N, K;
int visited[200004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    fill(&visited[0], &visited[0] + 200004, 987654321);
}

void display() {
    for (int i = 0; i <= 2 * K; i++) {
        cout << visited[i] << ' ';
    }
    cout << '\n';
}

void solve() {
    queue<int> q;
    q.push(N);
    visited[N] = 1;

    while (q.size()) {
        int cur = q.front();
        q.pop();

        if (cur == K)
            break;

        for (auto &next: {cur - 1, cur + 1, cur * 2}) {
            if (next < 0 || next >= 200004)
                continue;

            if (next == cur * 2) {
                visited[next] = visited[cur];
                q.push(next);
            } else {
                if (visited[next] > visited[cur] + 1) {
                    visited[next] = visited[cur] + 1;
                    q.push(next);
                }
            }
        }
    }

    cout << visited[K] - 1;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}