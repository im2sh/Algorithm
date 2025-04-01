#include <iostream>
#include <set>

using namespace std;

int N, M, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {

}

void solve() {
    while (cin >> N >> M) {
        ret = 0;
        for (int i = N; i <= M; i++) {
            string S = to_string(i);
            int len = S.length();
            if (len == size(set(S.begin(), S.end())))
                ret++;
        }
        cout << ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}