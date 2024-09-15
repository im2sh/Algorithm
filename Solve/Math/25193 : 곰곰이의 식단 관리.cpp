#include <iostream>

using namespace std;
int N, ret;
string S;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> S;
}

void solve() {
    int temp = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'C')
            ret++;
        else temp++;
    }

    if (ret % (temp + 1) != 0)
        cout << ret / (temp + 1) + 1;
    else
        cout << ret / (temp + 1);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}