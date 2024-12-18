#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, M, ret = -1;
vector<int> gimbap;
int low = 1;
int high;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K >> M;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        gimbap.push_back(temp);
        high = max(high, temp);
    }
}

bool check(int target) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int temp = gimbap[i];
        if (gimbap[i] <= K)
            continue;
        else if (gimbap[i] < 2 * K)
            temp -= K;
        else
            temp -= 2 * K;
        sum += temp / target;
    }
    if (sum >= M)
        return true;
    return false;
}

void solve() {
    while (low <= high) {
        int mid = (low + high) / 2;

        if (check(mid)) {
            ret = mid;
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