#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int N;
ll K, cnt;
vector<pair<int, int>> arr;

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
        arr.push_back({temp, i + 1});
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        cnt += arr[i].first;
        if (cnt > K) {
            cout << arr[i].second;
            return;
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        cnt += arr[i].first;
        if (cnt > K) {
            cout << arr[i].second;
            return;
        }
    }
    cout << arr[N * 2 - 1].second;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}