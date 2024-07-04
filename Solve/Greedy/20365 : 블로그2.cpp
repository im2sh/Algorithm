#include <iostream>

using namespace std;

int N, R, B, cnt, ret;
char arr[500004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    int ptr = 0;
    char temp = ' ';
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (i == 0) {
            arr[ptr] = temp;
            cnt++;
            ptr++;
        } else if (i != 0 && arr[ptr - 1] != temp) {
            arr[ptr] = temp;
            cnt++;
            ptr++;
        }
    }

    for (int i = 0; i < cnt - 1; i++) {
        if (arr[i] == 'R')
            R++;
        else if (arr[i] == 'B')
            B++;
    }
    if (R < B)
        ret += 1 + B;
    else
        ret += 1 + R;

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}