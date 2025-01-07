#include <iostream>

using namespace std;

int N, K;
int arr[4243];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }
}

void solve() {
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        for (int j = N - 1; j > i - 1; j--) {
            if (cnt >= K)
                break;
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            cnt++;
        }
        if (cnt >= K)
            break;
    }

    for (int i = 0; i < N; i++)
        cout << arr[i] << ' ';
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}