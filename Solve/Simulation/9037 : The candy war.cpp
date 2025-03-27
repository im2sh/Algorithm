#include <iostream>
#include <vector>

using namespace std;

int TC, N, C, ret;
vector<int> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void increase() {
    for (int i = 0; i < N; i++) {
        if (arr[i] % 2 == 1)
            arr[i]++;
    }
}

void Input() {
    cin >> N;
    ret = 0;
    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    increase();
}

bool check() {
    for (int i = 0; i < N - 1; i++) {
        if (arr[i] != arr[i + 1])
            return false;
    }
    return true;
}

void go() {
    vector<int> temp(N);
    for (int i = 0; i < N - 1; i++) {
        temp[i + 1] = arr[i] / 2;
    }
    temp[0] = arr[N - 1] / 2;
    for (int i = 0; i < N; i++) {
        arr[i] = arr[i] / 2 + temp[i];
    }
}

void solve() {
    while (TC--) {
        Input();
        while (!check()) {
            ret++;
            go();
            increase();
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