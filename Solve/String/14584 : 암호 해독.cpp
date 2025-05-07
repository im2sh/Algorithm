#include <iostream>
#include <string>

using namespace std;

int N;
string S;
string word[20];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> S;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> word[i];
    }
}

void solve() {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < N; j++) {
            if (S.find((word[j])) != string::npos) {
                cout << S;
                return;
            }
        }

        for (int j = 0; j < S.length(); j++) {
            S[j] = (S.at(j) - 'a' + 1) % 26 + 'a';
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}