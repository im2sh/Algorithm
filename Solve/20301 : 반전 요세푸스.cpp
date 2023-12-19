#include <iostream>
#include <deque>

using namespace std;
int N, K, M, cnt;
deque<int> dq;
bool check = true;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K >> M;
    for (int i = 1; i <= N; i++)
        dq.push_back(i);
}

void solve() {
    while (!dq.empty()) {
        if (check) {
            for (int i = 0; i < K - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            cout << dq.front() << '\n';
            dq.pop_front();

        } else {
            for (int i = 0; i < K - 1; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cout << dq.back() << '\n';
            dq.pop_back();
        }
        cnt++;
        if (cnt == M) {
            check = !check;
            cnt = 0;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}