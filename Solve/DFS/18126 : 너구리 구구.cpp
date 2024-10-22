#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

typedef struct Info {
    int end, weight;
};

int N;
ll ret;
vector<Info> graph[5001];
bool visited[5001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1].push_back({b - 1, c});
        graph[b - 1].push_back({a - 1, c});
    }
}

void dfs(int now, ll sum) {
    visited[now] = true;
    ret = max(ret, sum - 1);

    for (int i = 0; i < graph[now].size(); i++) {
        int next = graph[now][i].end;
        int weight = graph[now][i].weight;
        if (visited[next])
            continue;
        dfs(next, sum + weight);
    }
}

void solve() {
    dfs(0, 1);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}