#include <iostream>
#include <algorithm>

using namespace std;

int N, Q;
int arr[300004];
int prefix[300004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    sort(arr, arr + N);
    prefix[1] = arr[0];
    for (int i = 2; i <= N; i++)
        prefix[i] = prefix[i - 1] + arr[i - 1];
}

void solve() {
    while (Q--) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}