#include <iostream>
#include <algorithm>

using namespace std;

int N, ret;
string str[10];
int len[10];
int alpha[26];

bool cmp(int a, int b) {
    return a > b;
}

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str[i];
        len[i] = str[i].length();
    }
}

void solve() {
    int temp = 0;
    for (int i = 0; i < N; i++) {
        temp = 1;
        for (int j = len[i] - 1; j >= 0; j--) {
            alpha[str[i][j] - 'A'] += temp;
            temp *= 10;
        }
    }

    sort(alpha, alpha + 26, cmp);
    for (int i = 0; i < 10; i++) {
        ret += alpha[i] * (9 - i);
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << ret;
    return 0;
}