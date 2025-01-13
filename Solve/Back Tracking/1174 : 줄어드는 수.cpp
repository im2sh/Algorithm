#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void go(string S) {
    if (S.length() > 0)
        ret.push_back(stoll(S));

    for (int i = 0; i < 10; i++) {
        if (S.length() == 0 || (S[S.length() - 1] - '0') > i)
            go(S + to_string(i));
    }
}

void solve() {
    string temp = "";
    go(temp);
    sort(ret.begin(), ret.end());

    if (N > ret.size())
        cout << "-1";
    else
        cout << ret[N - 1];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}