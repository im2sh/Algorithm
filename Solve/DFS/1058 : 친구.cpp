#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, sum, ret;
vector<int> graph[51];
int visited[51];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;
            if (temp[j] == 'Y')
                graph[i].push_back(j);
        }
    }
}

void go(int start, int depth) {
    if (depth == 2)
        return;
    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        if (!visited[next])
            sum++;
        visited[next] = true;
        go(next, depth + 1);
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        fill(&visited[0], &visited[0] + 51, false);
        sum = 0;
        visited[i] = true;
        go(i, 0);
        ret = max(ret, sum);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
