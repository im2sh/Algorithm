#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[104];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
}

int go(int idx, int depth, int size) {
    if (depth > M)
        return 0;
    if (depth == M)
        return size;
    return max(go(idx + 1, depth + 1, size + arr[idx + 1]), go(idx + 2, depth + 1, size / 2 + arr[idx + 2]));
}

void solve() {
    cout << go(0, 0, 1);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}