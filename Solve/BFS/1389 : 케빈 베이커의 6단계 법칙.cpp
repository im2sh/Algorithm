#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, retNum = 987654321;
vector<vector<int>> adj;
int visited[101];
vector<int> retArr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        vector<int> temp;
        adj.push_back(temp);
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
}

void bfs(int start) {
    queue<int> q;
    visited[start] = 1;
    q.push(start);

    while (q.size()) {
        int here = q.front();
        q.pop();
        for (int i = 0; i < adj[here].size(); i++) {
            int next = adj[here][i];
            if (!visited[next]) {
                visited[next] = visited[here] + 1;
                q.push(next);
            }
        }
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        fill(&visited[0], &visited[0] + 101, 0);
        bfs(i);
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            cnt += visited[j] - 1;
        }
        retArr.push_back(cnt);
        retNum = min(retNum, cnt);
    }

    for (int i = 0; i < N; i++) {
        if (retArr[i] == retNum) {
            cout << i + 1;
            break;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}