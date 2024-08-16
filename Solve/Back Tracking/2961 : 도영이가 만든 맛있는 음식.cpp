#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int N;
int ret = INT_MAX;
vector<pair<int, int>> ingredient;
bool first = true;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        ingredient.push_back({a, b});
    }
}

void dfs(int idx, int S, int B) {
    if (!first)
        ret = min(ret, abs(S - B));

    for (int i = idx; i < N; i++) {
        first = false;
        dfs(i + 1, S * ingredient[i].first, B + ingredient[i].second);
    }
}

void solve() {
    dfs(0, 1, 0);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
