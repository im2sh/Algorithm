#include <iostream>
#include <utility>
#include <deque>

using namespace std;

int N;
deque<pair<int, int>> dq;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        dq.push_back(make_pair(temp, i + 1));
    }
}

void solve() {
    while (true) {
        int cnt = dq.front().first;
        cout << dq.front().second << " ";
        dq.pop_front();
        if (dq.empty())
            break;
        if (cnt > 0) {
            for (int i = 0; i < cnt - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            for (int i = cnt; i < 0; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
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