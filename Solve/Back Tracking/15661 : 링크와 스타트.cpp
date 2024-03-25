#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, ret = 987654321;
int BOARD[21][21];
int visited[21];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> BOARD[y][x];
        }
    }
}

int go() {
    vector<int> a;
    vector<int> b;
    int aSum = 0;
    int bSum = 0;

    for (int i = 0; i < N; i++) {
        if (visited[i])
            a.push_back(i);
        else
            b.push_back(i);
    }

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            if (i == j)
                continue;
            aSum += BOARD[a[i]][a[j]];
        }
    }
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (i == j)
                continue;
            bSum += BOARD[b[i]][b[j]];
        }
    }
    return abs(aSum - bSum);
}

void dfs(int idx, int depth) {
    if (depth >= 1) {
        ret = min(ret, go());
    }

    for (int i = idx; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(i, depth + 1);
            visited[i] = 0;
        }
    }
}

void solve() {
    dfs(0, 0);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}