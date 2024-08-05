#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, maxMoney, low, high, ret;
vector<int> area;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        area.push_back(temp);
        ret = max(ret, temp);
    }
    cin >> maxMoney;
    sort(area.begin(), area.end());
}

bool check(int mid) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (area[i] >= mid)
            sum += mid;
        else
            sum += area[i];
    }
    if (sum <= maxMoney)
        return true;
    return false;
}

void solve() {
    if (!check(maxMoney)) {
        high = maxMoney;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(mid)) {
                ret = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
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
