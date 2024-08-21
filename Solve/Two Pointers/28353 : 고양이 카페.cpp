#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, ret;
vector<int> v;

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
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
}

void solve() {
    int left = 0;
    int right = N - 1;

    while (right > left) {
        int temp = v[right] + v[left];

        if (temp > K)
            right--;
        else {
            right--;
            left++;
            ret++;
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