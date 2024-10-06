#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, card = 1;
vector<int> v;
deque<int> dq;

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
        v.push_back(temp);
    }
}

void solve() {
    for (int i = N - 1; i >= 0; i--) {
        if (v[i] == 1) {
            dq.push_back(card);
        } else if (v[i] == 2) {
            int temp = dq.back();
            dq.pop_back();
            dq.push_back(card);
            dq.push_back(temp);
        } else if (v[i] == 3) {
            dq.push_front(card);
        }
        card++;
    }

    for (int i = N - 1; i >= 0; i--)
        cout << dq[i] << ' ';
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}