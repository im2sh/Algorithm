#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
}

bool check(long long mid) {
    long long cnt = 0;
    for (int i = 0; i < N; i++)
        cnt += mid / v[i];

    if (cnt >= M)
        return true;
    return false;
}


void solve() {
    long long left = 1, right = 1e15, ret = -1;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (check(mid)) {
            ret = mid;
            right = mid - 1;
        } else left = mid + 1;
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}