#include <iostream>
#include <queue>

using namespace std;

int N;
int visited[1001][2];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    queue<pair<int, int>> q;
    q.push({1, 0});
    q.push({3, 0});

    while (q.size()) {
        int curPoint = q.front().first;
        int whoPoint = q.front().second;
        q.pop();

        if (curPoint == N) {
            if (whoPoint == 0)
                cout << "SK";
            else
                cout << "CY";
            return;
        }

        for (int x: {curPoint + 1, curPoint + 3}) {
            if (visited[x][whoPoint ^ 1])
                continue;
            q.push({x, whoPoint ^ 1});
            visited[x][whoPoint ^ 1] = 1;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}