#include <iostream>
#include <queue>

using namespace std;

int A, B, N, M;
int visited[100001];
int stone[100001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> A >> B >> N >> M;
}

void solve() {
    queue<int> q;
    visited[N] = 1;
    stone[N] = 0;
    q.push(N);
    int d[8] = {+1, -1, A, B, -A, -B, A, B};


    while (q.size()) {
        int cur = q.front();
        q.pop();

        if (cur == M) {
            cout << stone[cur];
            return;
        }

        for (int i = 0; i < 6; i++) {
            int next = cur + d[i];

            if (next < 0 || next > 100000)
                continue;

            if (!visited[next]) {
                visited[next] = true;
                stone[next] = stone[cur] + 1;
                q.push(next);
            }
        }

        for (int i = 6; i < 8; i++) {
            int next = cur * d[i];

            if (next < 0 || next > 100000)
                continue;
            if (!visited[next]) {
                visited[next] = true;
                stone[next] = stone[cur] + 1;
                q.push(next);
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
