#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, cy, cx, ret, skip;
vector<pair<int, int>> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> cx >> cy;
    arr.push_back({cx, cy});
}

void solve() {
    for (int i = 0; i < N - 1; i++) {
        int ny, nx;
        cin >> nx >> ny;
        arr.push_back({nx, ny});
        ret += abs(cx - nx) + abs(cy - ny);
        cx = nx;
        cy = ny;
    }

    for (int i = 1; i < N - 1; i++) {
        int totalD = abs(arr[i - 1].first - arr[i].first) + abs(arr[i - 1].second - arr[i].second) +
                     abs(arr[i].first - arr[i + 1].first) + abs(arr[i].second - arr[i + 1].second);
        int skipD = abs(arr[i - 1].first - arr[i + 1].first) + abs(arr[i - 1].second - arr[i + 1].second);
        skip = max(skip, totalD - skipD);
    }
    cout << ret - skip;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}