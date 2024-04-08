#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, N, K, ret = 987654321;
vector<int> charger;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> L >> N >> K;
    charger.push_back(0);
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        charger.push_back(temp);
    }
    charger.push_back(L);
}

bool check(int mid) {
    int gas = mid;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        int dist = charger[i] - charger[i - 1];
        gas -= dist;
        if (gas < 0) {
            return false;
        }
        if (gas < (charger[i + 1] - charger[i])) {
            gas = mid;
            cnt++;
        }
    }

    if (cnt > K || (gas + charger[N]) < L)
        return false;
    return true;
}

void solve() {
    int low = 0;
    int high = L;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (check(mid)) {
            ret = min(ret, mid);
            high = mid - 1;
        } else {
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