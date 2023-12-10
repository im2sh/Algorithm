#include <iostream>
#include <stack>

using namespace std;

int N, height;
stack<pair<int, int>> s;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 0; i < N; i++) {
        cin >> height;

        while (!s.empty()) {
            if (height < s.top().second) {
                cout << s.top().first << " ";
                break;
            }
            s.pop();
        }

        if (s.empty()) {
            cout << 0 << " ";
        }
        s.push({i + 1, height});
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
