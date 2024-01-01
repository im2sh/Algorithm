#include <iostream>

using namespace std;
int N;
int ret[9];
int visited[9];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void go(int depth) {
    if (depth == N) {
        for (int i = 0; i < depth; i++) {
            cout << ret[i] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            ret[depth] = i;
            go(depth + 1);
            visited[i] = false;
        }
    }
}

void solve() {
    go(0);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}