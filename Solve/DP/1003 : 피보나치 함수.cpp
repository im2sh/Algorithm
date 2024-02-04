#include <iostream>

using namespace std;

int TC;
int N;
int arr[41];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i < 41; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}

void solve() {
    while (TC--) {
        cin >> N;
        if (N == 0)
            cout << '1' << ' ' << '0' << '\n';
        else if (N == 1)
            cout << '0' << ' ' << '1' << '\n';
        else
            cout << arr[N - 1] << " " << arr[N] << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}