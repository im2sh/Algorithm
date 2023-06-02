#include <iostream>

using namespace std;

int N, M;
int people[101][101];
int visited[101];
int startA, startB;
int ret = -1;
bool ok = true;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int y, x;
    cin >> N;
    cin >> startA >> startB;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> y >> x;
        people[y][x] = 1;
        people[x][y] = 1;
    }
}

void solve(int y, int x, int cnt) {
    visited[y] = 1;
    if (visited[x] && ok) {
        ret = cnt;
        ok = false;
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (visited[i] || !people[y][i])
            continue;
        solve(i, x, cnt + 1);
    }
}

int main(void) {
    FastIO();
    Init();
    solve(startA, startB, 0);
    cout << ret << "\n";
    return 0;
}
