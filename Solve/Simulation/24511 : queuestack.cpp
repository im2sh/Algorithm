#include <iostream>
#include <deque>

using namespace std;

int N, M;
deque<int> dq;
bool flag[100001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> flag[i];
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (flag[i] == 0)
            dq.push_back(temp);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        dq.push_front(temp);
        cout << dq.back() << " ";
        dq.pop_back();
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}