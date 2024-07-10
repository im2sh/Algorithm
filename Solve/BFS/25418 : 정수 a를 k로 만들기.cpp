#include <iostream>
#include <queue>

using namespace std;

int A, K;
int visited[1000004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> A >> K;
}

int go() {
    queue<int> q;
    q.push(A);
    while (q.size()) {
        int cur = q.front();
        q.pop();

        if (cur == K)
            return visited[cur];
        if (cur + 1 <= 1000004 && !visited[cur + 1]) {
            q.push(cur + 1);
            visited[cur + 1] = visited[cur] + 1;
        }
        if (cur * 2 <= 1000004 && !visited[cur * 2]) {
            q.push(cur * 2);
            visited[cur * 2] = visited[cur] + 1;
        }
    }
}

void solve() {
    cout << go();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}