#include <iostream>

using namespace std;
int N, M;
bool button[101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> button[i];
    }
    cin >> M;
}

void goMan(int num) {
    for (int i = num; i <= N; i += num) {
        button[i] ^= 1;
    }
}

void goWoman(int num) {
    button[num] ^= 1;
    int start = num - 1;
    int end = num + 1;
    while (button[start] == button[end]) {
        if (start == 0 || end == N + 1)
            return;
        button[start] ^= 1;
        button[end] ^= 1;
        start--;
        end++;
    }
    return;
}

void solve() {
    for (int i = 0; i < M; i++) {
        int gender, light;
        cin >> gender >> light;

        if (gender == 1) {
            goMan(light);
        } else if (gender == 2) {
            goWoman(light);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << button[i] << " ";
        if (i % 20 == 0)
            cout << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}