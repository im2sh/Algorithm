#include <iostream>
#include <queue>

using namespace std;
int TC, N;
char card[1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void solve() {
    for (int i = 0; i < TC; i++) {
        deque<char> q;
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> card[j];
            if (j == 0)
                q.push_back(card[0]);
            else if (card[j] <= (q.front()))
                q.push_front(card[j]);
            else
                q.push_back(card[j]);
        }
        while (q.size()) {
            cout << q.front();
            q.pop_front();
        }
        cout << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}