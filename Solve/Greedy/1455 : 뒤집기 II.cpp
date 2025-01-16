#include <iostream>
#include <vector>

using namespace std;

int N, M, ret;
vector<vector<bool>> v;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    v.resize(N + 1, vector<bool>());
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++) {
            if (temp[j] == '0')
                v[i].push_back(0);
            else
                v[i].push_back(1);
        }
    }
}

void flip(int x, int y) {
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            v[i][j] = !v[i][j];
        }
    }
    ret++;
}

void solve() {
    for (int i = N - 1; i >= 0; i--) {
        for (int j = M - 1; j >= 0; j--) {
            if (v[i][j])
                flip(i, j);
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}