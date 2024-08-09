#include <iostream>

using namespace std;

int TC, N, cnt;
int arr[30001] = {2};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void go() {
    for (int i = 3; i <= 100000; i += 2) {
        bool flag = true;
        for (int j = 3; j <= sqrt(i); j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag)
            arr[++cnt] = i;
    }
}

void solve() {
    go();
    while (TC--) {
        cin >> N;
        for (int i = 0; i <= cnt; i++) {
            if (N == 1)
                break;
            int r = 0;
            while (!(N % arr[i])) {
                r++;
                N /= arr[i];
            }
            if (r)
                cout << arr[i] << ' ' << r << '\n';
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}