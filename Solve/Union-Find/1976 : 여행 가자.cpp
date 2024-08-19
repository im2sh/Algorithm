#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> graph[204];
int parent[204];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            if (i == j)
                continue;
            if (temp == 1) {
                graph[i + 1].push_back(j + 1);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
}

int getParent(int vertex) {
    if (parent[vertex] == vertex) {
        return vertex;
    }

    return parent[vertex] = getParent(parent[vertex]);
}

void unionParent(int x, int y) {
    x = getParent(x);
    y = getParent(y);

    if (x < y) {
        parent[y] = x;
    } else {
        parent[x] = y;
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            unionParent(i, graph[i][j]);
        }
    }
    int past = 0;
    cin >> past;
    for (int i = 1; i < M; i++) {
        int temp;
        cin >> temp;
        if (getParent(past) != getParent(temp)) {
            cout << "NO";
            return;
        }
        temp = past;
    }
    cout << "YES";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}