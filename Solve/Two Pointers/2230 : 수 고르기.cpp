#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll N, M;
ll ret = 2e16;
vector<ll> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
}

void solve() {
    int s = 0;
    int e = 1;

    while (s <= N && e <= N) {
        ll diff = arr[e] - arr[s];
        if (diff >= M) {
            ret = min(ret, diff);
            s++;
        } else {
            e++;
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