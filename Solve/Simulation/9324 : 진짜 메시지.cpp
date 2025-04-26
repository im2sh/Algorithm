#include <iostream>
#include <algorithm>

using namespace std;

int TC;
string S, ret;
bool flag = false;
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
    cin >> S;
    fill(&visited[0], &visited[0] + 26, 0);
    ret = "";
}

void solve() {
    while (TC--) {
        Input();
        for (int i = 0; i < S.length(); i++) {
            visited[S[i] - 'A']++;
            ret += S[i];

            if (visited[S[i] - 'A'] == 3) {
                visited[S[i] - 'A'] = 0;
                ret += S[i];
                i++;
            }
        }
        if (S == ret)
            cout << "OK\n";
        else
            cout << "FAKE\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}