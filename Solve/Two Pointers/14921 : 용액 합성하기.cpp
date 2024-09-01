#include <iostream>
#include <vector>

using namespace std;

int N, ret = 200000001;
vector<int> liquid;

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
        liquid.push_back(temp);
    }
}

void solve() {
    int start = 0;
    int end = N - 1;

    while (start < end) {
        int val = liquid[start] + liquid[end];

        if (abs(val) < abs(ret)) {
            ret = val;
        }
        if (ret == 0)
            break;
        else if (val < 0)
            start++;
        else
            end--;

    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
