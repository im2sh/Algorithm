#include <iostream>

using namespace std;

int N, D;
int digit[10];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> D;
}

void solve() {
    for (int i = 1; i <= N; i++) {
        string temp = to_string(i);
        for (int j = 0; j < temp.length(); j++) {
            digit[temp[j] - '0']++;
        }
    }
    cout << digit[D];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}