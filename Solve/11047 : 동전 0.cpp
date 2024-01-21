#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, ret;
vector<int> coins;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(int a, int b) {
    return a > b;
}

void Init() {
    int temp;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        coins.push_back(temp);
    }
    sort(coins.begin(), coins.end(), cmp);
}

void solve() {
    for (int i = 0; i < N; i++) {
        int coin = K / coins[i];
        if (coin > 0) {
            K %= coins[i];
            ret += coin;
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
