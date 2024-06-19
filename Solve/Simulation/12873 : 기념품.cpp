#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

typedef long long ll;

int N;
deque<int> dq;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }
}

void solve() {
    for (int i = 1; i <= N - 1; i++) {
        ll temp = pow(i, 3);
        temp--;
        temp %= (N - i + 1);

        while (temp--) {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        dq.pop_front();
    }
    cout << dq.front();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}