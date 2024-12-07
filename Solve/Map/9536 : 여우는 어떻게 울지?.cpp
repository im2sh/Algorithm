#include <iostream>
#include <map>

using namespace std;

int TC;
string S, ret;
map<string, bool> dict;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    dict.clear();
    ret = "";
    string buffer;
    getline(cin, buffer);
    getline(cin, S);
    while (true) {
        string a, b, c;
        cin >> a >> b >> c;
        if (a == "what") {
            cin >> b >> c;
            break;
        }
        dict[c] = true;
    }
}


void solve() {
    while (TC--) {
        Input();
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == ' ') {
                if (!dict[ret])
                    cout << ret << " ";
                ret = "";
            } else {
                ret += S[i];
            }
        }
        if (!dict[ret])
            cout << ret << " ";
        cout << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}