#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<int> graph[101];
int visited[101];
vector<int> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        graph[i].push_back(temp);
    }
}

void bfs(int cur) {
    queue<int> q;
    q.push(cur);
    bool flag = false;

    while (q.size()) {
        int now = q.front();
        q.pop();

        if (now == cur && flag) {
            ret.push_back(cur);
            return;
        }

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];

            if (visited[next])
                continue;
            q.push(next);
            visited[next] = 1;
            flag = true;
        }
    }
}


void solve() {
    for (int i = 1; i <= N; i++) {
        fill(&visited[0], &visited[0] + 101, 0);
        bfs(i);
    }

    sort(ret.begin(), ret.end());

    cout << ret.size() << '\n';
    for (int i = 0; i < ret.size(); i++) {
        if (i == ret.size() - 1)
            cout << ret[i];
        else
            cout << ret[i] << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}