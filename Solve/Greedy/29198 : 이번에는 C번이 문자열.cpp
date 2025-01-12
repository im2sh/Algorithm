#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
string ret;
string S[301];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        sort(S[i].begin(), S[i].end());
    }
    sort(S, S + N);
}

void solve() {
    for (int i = 0; i < K; i++) {
        ret += S[i];
    }
    sort(ret.begin(), ret.end());
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}