#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
int visited[1000001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> F >> S >> G >> U >> D;
}

void solve() {
    queue<int> q;
    q.push(S);
    visited[S] = 1;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        if (cur == G)
            break;
        for (auto it: {U, -D}) {
            int next = cur + it;
            if (next < 1 || next > F || visited[next])
                continue;
            q.push(next);
            visited[next] = visited[cur] + 1;
        }
    }
    if (visited[G])
        cout << visited[G] - 1;
    else
        cout << "use the stairs";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}