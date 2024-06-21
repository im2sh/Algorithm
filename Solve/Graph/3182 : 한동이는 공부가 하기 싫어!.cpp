#include <iostream>
#include <algorithm>

using namespace std;

int N, meet, ret;
int graph[1001];
bool visited[1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        graph[i] = --temp;
    }
}

void solve() {
    for (int i = 0; i < N; ++i) {
        fill(&visited[0], &visited[0] + 1001, 0);
        int cur = i;
        int cnt = 0;
        while (!visited[cur]) {
            visited[cur] = true;
            cur = graph[cur];
            ++cnt;
        }

        if (cnt > meet) {
            meet = cnt;
            ret = i;
        }
    }
    cout << ret + 1;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}