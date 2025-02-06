#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll N, K, A, B;
vector<ll> V;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        V.push_back(B - A);
    }
}

void solve() {
    sort(V.begin(), V.end());
    cout << max(0LL, V[K - 1]);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}