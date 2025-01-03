#include <iostream>
#include <vector>

using namespace std;

int N, M, ret;
vector<int> arr;
vector<bool> visited(1 << 21, false);

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    arr.resize(N + 1, 0);
}

void solve() {
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b;

        if (a == 1) {
            cin >> c;
            arr[b] |= (1 << c);
        } else if (a == 2) {
            cin >> c;
            arr[b] &= ~(1 << c);
        } else if (a == 3) {
            arr[b] = arr[b] << 1;
            arr[b] &= ((1 << 21) - 1);
        } else if (a == 4) {
            arr[b] = arr[b] >> 1;
            arr[b] &= ~1;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[arr[i]])
            ret++;
        visited[arr[i]] = true;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}