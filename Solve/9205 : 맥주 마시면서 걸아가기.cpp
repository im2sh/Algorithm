#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int T, N;
int sy, sx, cy, cx, ey, ex;
vector<pair<int, int>> v;
int visited[101];
bool flag = false;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> T;
}

void Info_Init() {
    v.clear();
    flag = false;
    cin >> N;
    cin >> sy >> sx;
    for (int i = 0; i < N; i++) {
        cin >> cy >> cx;
        v.push_back({cy, cx});
    }
    cin >> ey >> ex;
    fill(&visited[0], &visited[0] + 101, 0);
}

void dfs(int y, int x) {
    int dist = (abs(ey - y) + abs(ex - x));
    if (dist <= 1000) {
        flag = true;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i] && ((abs(v[i].first - y) + abs(v[i].second - x)) <= 1000)) {
            visited[i] = 1;
            dfs(v[i].first, v[i].second);
        }
    }
}

void solve() {
    while (T--) {
        Info_Init();
        dfs(sy, sx);
        if (flag)
            cout << "happy" << '\n';
        else
            cout << "sad" << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}