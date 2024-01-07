#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int N, M;
ll low, high = 1000000004;
ll ret = 1000000004;
vector<int> money;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    ll temp;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        money.push_back(temp);
        low = max(low, temp);
        high += temp;
    }
}

bool moneyCheck(ll mid) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        sum += money[i];
        if (sum > mid) {
            count++;
            sum = 0;
            sum += money[i];
        }
    }
    if (sum != 0) {
        count++;
    }
    return count <= M;
}

void solve() {
    ll mid = (low + high) / 2;
    while (low <= high) {
        if (moneyCheck(mid)) {
            ret = min(ret, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}