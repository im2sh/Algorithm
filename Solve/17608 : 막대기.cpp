#include <iostream>
#include <stack>

using namespace std;

int n, m, ret, maxNum;
stack<int> s;

void FastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        s.push(m);
    }
}

void solve() {
    while (s.size()) {
        if (maxNum < s.top()) {
            maxNum = s.top();
            ret++;
        }
        s.pop();
    }
    cout << ret;
}

int main() {
    FastIO();
    Init();
    solve();
    return 0;
}