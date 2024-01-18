#include <iostream>
#include <queue>

using namespace std;

const int moveCommand[3] = {-1, 1, 2};

int N, K;
int visited[100001];
queue<int> q;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
}

void solve() {
    q.push(N);
    visited[N] = 1;
    while (q.size()) {
        int cur = q.front();
        if (cur == K)
            break;
        q.pop();
        for (int M: moveCommand) {
            int next = 0;
            if (M == 2) {
                next = 2 * cur;
            } else {
                next = cur + M;
            }
            if (next < 0 || next > 100000 || visited[next])
                continue;
            q.push(next);
            visited[next] = visited[cur] + 1;
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