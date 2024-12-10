#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, L, ret;
vector<int> house;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> L;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        house.push_back(temp);
    }
    house.push_back(0);
    house.push_back(L);
    sort(house.begin(), house.end());
}

bool check(int mid) {
    int cnt = 0;

    for (int i = 1; i < house.size(); i++) {
        int diff = house[i] - house[i - 1];
        cnt += diff / mid;
        if (diff % mid == 0)
            cnt--;
    }

    if (cnt > M)
        return false;
    return true;
}

void solve() {
    int low = 0;
    int high = L;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (check(mid)) {
            ret = mid;
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