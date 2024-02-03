#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned long long ull;

using namespace std;

ull N, M, ret;
vector<ull> checkin;
ull low, high;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    ull temp;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        checkin.push_back(temp);
    }
    sort(checkin.begin(), checkin.end());
}

void solve() {
    low = 1;
    high = M * checkin[checkin.size() - 1];
    ret = M * checkin[checkin.size() - 1];

    while (low <= high) {
        ull mid = (low + high) / 2;
        ull cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += mid / checkin[i];
        }
        if (cnt >= M) {
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