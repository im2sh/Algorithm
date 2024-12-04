#include <iostream>
#include <vector>

using namespace std;

int N, Q;
vector<vector<int>> graph;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    graph.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin >> Q;
}

void solve() {
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            if (graph[b].size() > 1)
                cout << "yes\n";
            else
                cout << "no\n";
        } else {
            cout << "yes\n";
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

