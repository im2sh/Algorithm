#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
long long ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
}

void solve() {
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
        ret += abs((i + 1) - v[i]);
}

int main() {
    FastIO();
    Init();
    solve();
    cout << ret;
    return 0;
}