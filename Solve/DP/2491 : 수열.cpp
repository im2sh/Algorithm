#include <iostream>
#include <algorithm>

using namespace std;

int N, maxNum = -1;
int arr[100001], bdp[100001], mdp[100001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 0; i < N; i++) {
        bdp[i] = 1;
        mdp[i] = 1;
        cin >> arr[i];
        if (i != 0) {
            if (arr[i] >= arr[i - 1])
                bdp[i] = bdp[i - 1] + 1;
            if (arr[i] <= arr[i - 1])
                mdp[i] = mdp[i - 1] + 1;
            maxNum = max(maxNum, max(mdp[i], bdp[i]));
        }
    }
    if (N == 1)
        cout << "1";
    else
        cout << maxNum;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
