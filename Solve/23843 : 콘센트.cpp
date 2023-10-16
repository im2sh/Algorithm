#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
priority_queue<int, vector<int>, greater<int>> pq;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
}

void solve() {
    sort(v.begin(), v.end(), greater<int>());

    for (int i = 0; i < min(N, M); i++) {
        pq.push(v[i]);
    }
    for (int i = M; i < N; i++) {
        int top = pq.top();
        pq.pop();
        pq.push(v[i] + top);
    }

    while (pq.size() != 1)
        pq.pop();

    cout << pq.top();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

