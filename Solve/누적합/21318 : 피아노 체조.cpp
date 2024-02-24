#include <iostream>

using namespace std;
int N, Q;
int piano[100001];
int prefix[100001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> piano[i];
    }

    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i] + prefix[i - 1];
        if (piano[i] < piano[i - 1])
            prefix[i] += 1;
    }
    cin >> Q;
}

void solve() {
    int s, e;
    for (int i = 0; i < Q; i++) {
        cin >> s >> e;
        cout << prefix[e] - prefix[s] << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}