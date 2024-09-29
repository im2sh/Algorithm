#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> a;
vector<ll> b;
ll N, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll temp;
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < N; i++) {
        ll temp;
        cin >> temp;
        b.push_back(temp);
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        ret = upper_bound(b.begin(), b.end(), a[i]) - b.begin() - i - 1;
        cout << ret;
        if (i != N - 1)
            cout << " ";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}