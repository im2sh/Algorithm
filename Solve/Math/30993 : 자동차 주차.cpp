#include <iostream>

using namespace std;

typedef long long ll;

ll N, A, B, C;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> A >> B >> C;
}

ll go(int num) {
    ll sum = 1;
    while (num) {
        sum *= num;
        num--;
    }
    return sum;
}

void solve() {
    cout << go(N) / (go(A) * go(B) * go(C));
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}