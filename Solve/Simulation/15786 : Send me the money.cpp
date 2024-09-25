#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
string alpha;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    cin >> alpha;
}

void solve() {
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        string temp = alpha;
        reverse(temp.begin(), temp.end());
        for (int j = 0; j < s.length(); j++) {
            if (temp.back() == s[j])
                temp.pop_back();
        }
        if (!temp.size())
            cout << "true\n";
        else
            cout << "false\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}