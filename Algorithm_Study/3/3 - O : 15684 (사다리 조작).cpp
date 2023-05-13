#include <iostream>
#include <algorithm>

using namespace std;

int N, M, H;
int ret = 987654321;
int ladder[31][31];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> H;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        ladder[a][b] = 1;
    }
}

bool check() {
    for (int i = 1; i <= N; i++) {
        int start = i;
        for (int j = 1; j <= H; j++) {
            if (ladder[j][start])
                start++;
            else if (ladder[j][start - 1])
                start--;
        }
        if (i != start)
            return false;
    }
    return true;
}

void solve(int start, int cnt) {
    if (cnt >= ret || cnt > 3)
        return;
    if (check()) {
        ret = min(ret, cnt);
        return;
    }
    for (int i = start; i <= H; i++) {
        for (int j = 1; j <= N; j++) {
            if (ladder[i][j] || ladder[i][j - 1] || ladder[i][j + 1])
                continue;
            ladder[i][j] = 1;
            solve(i, cnt + 1);
            ladder[i][j] = 0;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve(1, 0);
    if (ret == 987654321)
        ret = -1;
    cout << ret << "\n";
    return 0;
}