#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S, ret;
vector<int> cow;

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
        cow.push_back(temp);
    }
    sort(cow.begin(), cow.end());
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int sum = cow[i] + cow[j];
            if (sum > S)
                break;
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