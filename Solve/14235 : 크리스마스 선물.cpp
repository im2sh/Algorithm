#include <iostream>
#include <queue>

using namespace std;

int N, A, present;
priority_queue<int> pq;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    while (N--) {
        cin >> A;
        if (A == 0) {
            if (pq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            while (A--) {
                cin >> present;
                pq.push(present);
            }
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}


