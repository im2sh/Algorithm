#include <iostream>
#include <climits>

using namespace std;
int N;
long long ret;
int cost[100001];
int dist[100001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> dist[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }
}

void solve() {
    int min = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (cost[i] < min)
            min = cost[i];
        ret += (long long) min * (long long) dist[i];
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}