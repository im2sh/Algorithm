#include <iostream>
#include <queue>

using namespace std;

int N;
vector<int> graph[101];
int ret[101][101];
bool visited[101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> temp;
            if (temp == 1) {
                graph[y].push_back(x);
            }
        }
    }
}

void go(int here) {
    queue<int> q;
    q.push(here);
    visited[here] = true;

    while (q.size()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (next == here)
                ret[here][here] = 1;
            if (visited[next])
                continue;
            q.push(next);
            visited[next] = true;
            ret[here][next] = 1;
        }
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        fill(&visited[0], &visited[0] + 101, false);
        go(i);
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << ret[y][x] << ' ';
        }
        if (y != N - 1)
            cout << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}