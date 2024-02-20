#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;
vector<int> graph[1004];
vector<int> ret;
int indegree[1004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp, x, past = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        past = 0;
        cin >> temp;
        for (int j = 0; j < temp; j++) {
            cin >> x;
            if (past == 0) {
                past = x;
                continue;
            }
            graph[past].push_back(x);
            indegree[x]++;
            past = x;
        }
    }
}

void solve() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (!indegree[i]) {
            q.push(i);
        }
    }

    if (q.empty()) {
        cout << "0";
        return;
    }

    while (q.size()) {
        int x = q.front();
        ret.push_back(x);
        q.pop();

        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            indegree[y]--;
            if (!indegree[y]) {
                q.push(y);
            }
        }
    }

    if (ret.size() == N) {
        for (int i = 0; i < N; i++) {
            cout << ret[i] << '\n';
        }
    } else {
        cout << "0";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}