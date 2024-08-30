#include <iostream>

using namespace std;

int N, K;
int prefix[100001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    prefix[0] = 0;
    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        if (i == 1)
            prefix[i] = temp;
        else
            prefix[i] = prefix[i - 1] + temp;
    }
    cin >> K;
}

void solve() {
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}