#include <iostream>

using namespace std;

string S, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    getline(cin, S);
}

void solve() {
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'U' && ret.empty()) {
            ret += 'U';
        } else if (S[i] == 'C' && ret == "U") {
            ret += 'C';
        } else if (S[i] == 'P' && ret == "UC") {
            ret += 'P';
        } else if (S[i] == 'C' && ret == "UCP") {
            ret += 'C';
        }
    }

    if (ret == "UCPC") {
        cout << "I love UCPC";
    } else {
        cout << "I hate UCPC";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}