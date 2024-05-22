#include <iostream>
#include <algorithm>

using namespace std;
int N;
string S;
int alpha[26];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void go(int depth, string temp) {
    if (depth == S.length()) {
        cout << temp << '\n';
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (!alpha[i])
            continue;
        alpha[i]--;
        temp += i + 'a';
        go(depth + 1, temp);
        temp.pop_back();
        alpha[i]++;
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        fill(&alpha[0], &alpha[0] + 26, 0);
        string temp;
        cin >> S;
        sort(S.begin(), S.end());
        for (char c: S) {
            alpha[c - 'a']++;
        }
        go(0, temp);
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}