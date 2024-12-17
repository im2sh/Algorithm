#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int TC;
int original, target;
bool visited[10004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    fill(&visited[0], &visited[0] + 10004, false);
    cin >> original >> target;
}

void go() {
    queue<pair<int, string>> q;
    string temp = "";
    q.push({original, temp});
    int cnt = 0;
    while (q.size()) {
        cnt++;
        int now = q.front().first;
        string nowCommand = q.front().second;
        if (now == target) {
            cout << nowCommand << '\n';
            return;
        }
        q.pop();

        // 1. D
        int D = (now * 2) % 10000;
        if (!visited[D])
            q.push({D, nowCommand + "D"});

        // 2. S
        int S = now - 1;
        if (S < 0)
            S = 9999;
        if (!visited[S])
            q.push({S, nowCommand + "S"});

        // 3. L
        int L = 0;
        L = (now % 1000) * 10 + now / 1000;
        if (!visited[L])
            q.push({L, nowCommand + "L"});

        // 4. R
        int R = 0;
        R = (now % 10) * 1000 + (now / 10);
        if (!visited[R])
            q.push({R, nowCommand + "R"});

        visited[S] = true, visited[S] = true, visited[L] = true, visited[R] = true;
    }
}

void solve() {
    while (TC--) {
        Input();
        go();
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}