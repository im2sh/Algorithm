#include <iostream>

using namespace std;

int N, Q, S;
long long arr[200001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void solve() {
    for (int i = 0; i < Q; i++) {
        int x, k;
        cin >> x;

        if (x == 1) {
            int temp;
            cin >> k >> temp;
            k -= 1;
            arr[(S + k) % N] += temp;
        } else if (x == 2) {
            cin >> k;
            S = (S + N - k) % N;
        } else if (x == 3) {
            cin >> k;
            S = (S + k) % N;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << arr[(S + i) % N] << ' ';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}