#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
vector<ll> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        reverse(S.begin(), S.end());
        ret.push_back(stol(S));
    }

    sort(ret.begin(), ret.end());
    for (int i = 0; i < N; i++) {
        cout << ret[i] << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}