#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S, ret = 987654321;
vector<int> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
}

void solve() {
    int low = 0;
    int high = 0;
    int sum = arr[low];

    while (low <= high && high <= N) {
        if (sum >= S)
            ret = min(ret, (high - low) + 1);
        if (sum >= S)
            sum -= arr[low++];
        else
            sum += arr[++high];
    }
    if (ret == 987654321)
        cout << "0";
    else
        cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}