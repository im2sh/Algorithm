#include <iostream>

using namespace std;

int N, M, ret;
bool visited[204][204];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        visited[A][B] = true;
        visited[B][A] = true;
    }
}

void solve() {
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (visited[i][j])
                continue;
            for (int k = j + 1; k <= N; ++k) {
                if (visited[i][k] || visited[j][k])
                    continue;
                ret++;
            }
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