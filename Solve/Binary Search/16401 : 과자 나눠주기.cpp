#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, ret;
vector<int> snack;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        snack.push_back(temp);
    }
    sort(snack.begin(), snack.end());
}

void solve() {
    int low = 1;
    int high = snack[N - 1];

    while (low <= high) {
        int mid = (low + high) / 2;

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += snack[i] / mid;
        }
        if (cnt < M) {
            high = mid - 1;
        } else {
            ret = mid;
            low = mid + 1;
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