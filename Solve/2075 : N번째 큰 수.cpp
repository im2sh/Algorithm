#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int> > pq;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    int temp;
    for (int i = 0; i < N * N; i++) {
        cin >> temp;
        pq.push(temp);
        if (pq.size() > N) {
            pq.pop();
        }
    }
    cout << pq.top() << '\n';
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

