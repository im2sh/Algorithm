#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M, ret;
vector<int> ax, ay;
int x, y;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int tx, ty;
        cin >> tx >> ty;
        ax.push_back(tx);
        ay.push_back(ty);
    }
    sort(ax.begin(), ax.end());
    sort(ay.begin(), ay.end());
    x = ax[M / 2];
    y = ay[M / 2];
}

int getDistance(int tx, int ty) {
    return abs(x - tx) + abs(y - ty);
}

void solve() {
    for (int i = 0; i < M; i++) {
        ret += getDistance(ax[i], ay[i]);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}