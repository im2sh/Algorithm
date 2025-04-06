#include <iostream>
#include <algorithm>

using namespace std;

int TC, K, ret1, ret2;
string S;
int visited[26];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    ret1 = 10000;
    ret2 = 0;
    cin >> S;
    cin >> K;
}

void go() {
    vector<int> pos[26];

    for (int i = 0; i < S.length(); i++) {
        pos[S[i] - 'a'].push_back(i);
    }

    for (int c = 0; c < 26; c++) {
        if (pos[c].size() < K)
            continue;

        for (int i = 0; i <= pos[c].size() - K; i++) {
            int len = pos[c][i + K - 1] - pos[c][i] + 1;
            ret1 = min(ret1, len);
            ret2 = max(ret2, len);
        }
    }
}

void solve() {
    while (TC--) {
        Input();
        go();
        if (ret1 == 10000 || ret2 == 0)
            cout << "-1\n";
        else
            cout << ret1 << ' ' << ret2 << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}