#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, ret = 987654321;
vector<int> bridge;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        bridge.push_back(temp);
    }
}

void solve() {
    int low = 0;
    int high = 100000;

    while (low <= high) {
        int mid = (low + high) / 2;

        bool visited = true;
        if (bridge[0] > mid)
            visited = false;

        for (int i = 0; i < M - 1; i++) {
            if (bridge[i + 1] - bridge[i] > mid * 2) {
                visited = false;
                break;
            }
        }

        if (N - bridge[M - 1] > mid)
            visited = false;

        if (!visited) {
            low = mid + 1;
        } else {
            ret = min(ret, mid);
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