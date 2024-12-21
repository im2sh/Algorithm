#include <iostream>
#include <set>

using namespace std;

string S;
set<string> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> S;
}

void go(int left, int right, string str, string path) {
    if (left == 0 && right == S.length() - 1) {
        ret.insert(path);
        return;
    }

    if (left - 1 >= 0)
        go(left - 1, right, S[left - 1] + str, path + S[left - 1] + str);

    if (right + 1 < S.length())
        go(left, right + 1, str + S[right + 1], path + str + S[right + 1]);
}

void solve() {
    for (int i = 0; i < S.length(); i++) {
        string path = "";
        path += S[i];
        string str = "";
        str += S[i];
        go(i, i, str, path);
    }
    
    if (ret.size())
        cout << ret.size();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}