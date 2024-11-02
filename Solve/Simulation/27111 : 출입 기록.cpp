#include <iostream>

using namespace std;

int N, ret;
int arr[200001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    while (N--) {
        int a, b;
        cin >> a >> b;
        if (b) {
            if (arr[a])
                ret++;
            else
                arr[a] = 1;
        } else {
            if (!arr[a])
                ret++;
            else
                arr[a] = 0;
        }
    }

    for (int i = 1; i < 200001; i++)
        ret += arr[i];

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}