#include <iostream>
#include <queue>

using namespace std;

int N;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    queue<int> q;
    int x;
    string command;
    for (int i = 0; i < N; i++) {
        cin >> command;

        if (command == "push") {
            cin >> x;
            q.push(x);
        } else if (command == "pop") {
            if (!q.empty()) {
                cout << q.front() << '\n';
                q.pop();
            } else cout << -1 << '\n';

        } else if (command == "size") {
            cout << q.size() << '\n';
        } else if (command == "empty") {
            cout << q.empty() << '\n';
        } else if (command == "front") {
            if (!q.empty())
                cout << q.front() << '\n';
            else
                cout << -1 << '\n';
        } else {
            if (!q.empty())
                cout << q.back() << '\n';
            else
                cout << -1 << '\n';
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}