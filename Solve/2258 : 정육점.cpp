#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, ret = 2147483647;
vector<pair<int, int>> meat;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
}

void Init() {
    int a, b;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        meat.push_back({a, b});
    }
    sort(meat.begin(), meat.end(), cmp);
}

void solve() {
    int sum = 0;
    int temp = 0;
    int before = 0;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        sum += meat[i].first;
        if (meat[i].second == before)
            temp += meat[i].second;
        else
            temp = meat[i].second;
        if (sum >= M) {
            ret = min(ret, temp);
            flag = true;
        }
        before = meat[i].second;
    }
    if (flag)
        cout << ret;
    else
        cout << -1;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}