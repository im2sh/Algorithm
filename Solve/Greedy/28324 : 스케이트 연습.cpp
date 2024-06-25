#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int N, cur = 1;
vector<int> arr;
ll ret = 1;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
}

void solve() {
    for (int i = N - 2; i >= 0; i--) {
        if (arr[i] <= cur) {
            cur = arr[i];
            ret += cur;
        } else {
            ++cur;
            ret += cur;
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