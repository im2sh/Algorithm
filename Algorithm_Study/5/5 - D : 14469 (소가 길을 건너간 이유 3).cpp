#include <iostream>
#include <vector>

using namespace std;

int N;
int T;
vector<pair<int, int>> cow;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int x, y;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        cow.push_back({x, y});
    }
}

void solve() {
    sort(cow.begin(), cow.end());
    T = cow[0].first + cow[0].second;
    for (int i = 1; i <= N; i++) {
        if (cow[i].first > T)
            T = cow[i].first + cow[i].second;
        else
            T += cow[i].second;
    }
    cout << T << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}