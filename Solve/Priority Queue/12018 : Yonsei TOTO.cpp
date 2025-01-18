#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, P, L, sum, ret;
priority_queue<int, vector<int>, greater<int>> pq;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> P >> L;

        vector<int> v;
        for (int j = 0; j < P; j++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        sort(v.begin(), v.end());

        if (v.size() < L)
            pq.push(1);
        else
            pq.push(v[P - L]);
    }
}

void solve() {
    while (pq.size()) {
        if (sum + pq.top() > M)
            break;
        sum += pq.top();
        pq.pop();
        ret++;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}