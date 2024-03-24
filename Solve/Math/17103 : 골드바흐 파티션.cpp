#include <iostream>

using namespace std;
int TC, N, ret;
bool arr[1000001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
    for (int i = 0; i < 1000001; i++) {
        arr[i] = true;
    }
    arr[0] = arr[1] = false;

    for (int i = 2; i * i < 1000001; i++) {
        if (arr[i]) {
            for (int j = i * 2; j <= 1000001; j += i) {
                arr[j] = false;
            }
        }
    }
}

void solve() {
    while (TC--) {
        cin >> N;
        ret = 0;

        for (int i = 0; i <= N / 2; i++) {
            int a = i;
            int b = N - i;

            if (arr[a] && arr[b]) {
                ret++;
            }
        }

        cout << ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}