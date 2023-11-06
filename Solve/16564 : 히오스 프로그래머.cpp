#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> level;
int ret;
long long need = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        level.push_back(temp);
    }
    sort(level.begin(), level.end());
}

void solve() {
    int l = level[0];
    int r = level[0] + K;
    int mid = 0;

    while (l <= r) {
        mid = (l + r) / 2, need = 0;

        for (int i = 0; i < N; i++) {
            if (level[i] < mid)
                need += mid - level[i];
            else break;
        }
        if (need > K)
            r = mid - 1;
        else {
            ret = mid;
            l = mid + 1;
        }
    }
    cout << ret;
}

int main() {
    FastIO();
    Init();
    solve();
    return 0;
}
