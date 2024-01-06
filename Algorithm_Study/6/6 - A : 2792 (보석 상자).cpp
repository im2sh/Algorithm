#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;
ll N, M, ret = 987654321;
vector<ll> box;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    ll temp;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        box.push_back(temp);
    }
    sort(box.begin(), box.end());
}

bool check(ll mid) {
    int sum = 0;
    for (int i = 0; i < M; i++) {
        int target = box[i];
        sum += target / mid;
        if (target % mid)
            sum++;
    }
    return sum <= N;
}

void solve() {
    ll left = 1;
    ll right = box[M - 1];
    ll mid = (left + right) / 2;

    while (left <= right) {
        if (check(mid)) {
            right = mid - 1;
            ret = min(ret, mid);
        } else {
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}