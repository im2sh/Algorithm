#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;
int target;
int ret;
int s, e;


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    cin >> target;
}

void solve() {
    sort(arr.begin(), arr.end());
    e = N - 1;
    while (s < e) {
        int sum = arr[s] + arr[e];
        if (sum <= target)
            s++;
        else
            e--;
        if (sum == target)
            ret++;
    }
    cout << ret << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}