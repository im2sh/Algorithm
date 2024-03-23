#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int N, ret;
string arr[51];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
}

void solve() {
    ret = N;

    for (int i = 0; i < N; i++) {
        string temp = arr[i + 1].substr(0, arr[i].size());
        if (temp == arr[i]) {
            ret--;
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}