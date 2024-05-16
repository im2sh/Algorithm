#include <iostream>

using namespace std;
int N, S, ret;
int arr[21];
bool visited[21];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void go(int idx, int sum) {
    if (sum == S)
        ret++;

    for (int i = idx; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            go(i + 1, sum + arr[i]);
            visited[i] = false;
        }
    }
}

void solve() {
    go(0, 0);
    if (S == 0)
        cout << ret - 1;
    else
        cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
