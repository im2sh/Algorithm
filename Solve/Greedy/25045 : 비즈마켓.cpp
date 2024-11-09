#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, M;
ll ret;
vector<ll> A;
vector<ll> B;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        ll temp;
        cin >> temp;
        A.push_back(temp);
    }

    for (int i = 0; i < M; i++) {
        ll temp;
        cin >> temp;
        B.push_back(temp);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
}

void solve() {
    for (int i = 0; i < min(N, M); i++) {
        if (A[N - 1 - i] - B[i] >= 0)
            ret += A[N - 1 - i] - B[i];
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}