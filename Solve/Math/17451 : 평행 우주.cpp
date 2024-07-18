#include <iostream>

using namespace std;

typedef long long ll;
int N;
int planet[300004];
ll ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> planet[i];
    }
    ret = planet[N - 1];
}

void solve() {
    for (int i = N - 2; i >= 0; i--) {
        if (planet[i] > ret) {
            ret = planet[i];
        } else {
            if (ret % planet[i])
                ret = (ret / planet[i] + 1) * planet[i];
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}