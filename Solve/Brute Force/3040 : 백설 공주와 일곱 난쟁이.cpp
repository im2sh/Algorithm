#include <iostream>

using namespace std;
int sum, ret;
int arr[9];
pair<int, int> idx;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
}

void solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (i == j || (sum - arr[i] - arr[j] != 100))
                continue;
            ret = 1;
            idx = {i, j};
            break;
        }
        if (ret == 1)
            break;
    }

    for (int i = 0; i < 9; i++) {
        if (i != idx.first && i != idx.second)
            cout << arr[i] << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
