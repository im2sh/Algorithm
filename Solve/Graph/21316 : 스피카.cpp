#include <iostream>

using namespace std;

vector<int> graph[12];
bool visited[4];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    for (int i = 0; i < 12; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
}

void solve() {
    for (int i = 0; i < 12; i++) {
        if (graph[i].size() == 3) {
            fill(&visited[0], &visited[0] + 4, false);
            bool flag = true;
            for (int j = 0; j < graph[i].size(); j++) {
                visited[graph[graph[i][j]].size()] = true;
            }
            for (int j = 1; j < 4; j++) {
                if (!visited[j])
                    flag = false;
            }
            if (flag)
                cout << i + 1;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}