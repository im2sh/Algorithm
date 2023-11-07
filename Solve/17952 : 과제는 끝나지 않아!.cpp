#include <iostream>
#include <stack>

using namespace std;

int N;
int ret;
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
    while (N--) {
        bool temp;
        cin >> temp;
        if (temp) {
            int a, b;
            cin >> a >> b;
            s.push({a, b});
        }
        if (!s.empty()) {
            s.top().second--;
            if (s.top().second == 0)//다했으면 이전 과제
            {
                ret += s.top().first;
                s.pop();
            }
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

