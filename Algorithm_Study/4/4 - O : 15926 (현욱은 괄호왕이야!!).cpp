#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int N;
string g;
stack<int> temp;
int ret = 0;
int result[200001];
int cnt = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> g;
}

void solve() {
    for (int i = 0; i < g.length(); i++) {
        if (g[i] == '(') {
            temp.push(i + 1);
        } else if (temp.size()) {
            result[i + 1] = 1;
            result[temp.top()] = 1;
            temp.pop();
        }
    }

    for (int i = 1; i <= N; i++) {
        if (result[i]) {
            cnt++;
            ret = max(ret, cnt);
        } else
            cnt = 0;
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << ret << "\n";
    return 0;
}
