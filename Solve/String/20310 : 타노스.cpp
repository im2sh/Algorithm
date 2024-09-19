#include <iostream>

using namespace std;

string S, ret;
int zero, one, removedZero, removedOne;
bool visited[504];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> S;
}

void solve() {
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '0')
            zero++;
        else
            one++;
    }

    for (int i = 0; i < S.size(); i++) {
        if (removedOne == one / 2)
            break;
        if (S[i] == '1') {
            removedOne++;
            visited[i] = true;
        }
    }

    for (int i = S.size() - 1; i >= 0; i--) {
        if (removedZero == zero / 2)
            break;
        if (S[i] == '0') {
            removedZero++;
            visited[i] = true;
        }
    }
    for (int i = 0; i < S.size(); i++) {
        if (visited[i])
            continue;
        ret += S[i];
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
