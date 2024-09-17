#include <iostream>

using namespace std;

typedef long long ll;
constexpr ll MOD = 1e9 + 7;

ll mul = 1, ret = 0;
string S;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> S;
}

void solve() {
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'O')
            ret += mul;
        ret %= MOD;
        mul *= 2;
        mul %= MOD;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}