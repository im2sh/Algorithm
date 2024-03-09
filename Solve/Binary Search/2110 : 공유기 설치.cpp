#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, C;
ll ret;
vector<int> house;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        house.push_back(temp);
    }
    sort(house.begin(), house.end());
}

bool check(int target) {
    int h = house[0];
    int cnt = 1;
    for (int i = 1; i < N; i++) {
        if (house[i] - h >= target) {
            cnt++;
            h = house[i];
        }
    }
    if (cnt >= C)
        return true;
    return false;
}

void solve() {
    int low = 0;
    int high = house[house.size() - 1];

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (check(mid)) {
            ret = max(ret, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
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