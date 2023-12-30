#include <iostream>
#include <queue>

using namespace std;

int N, ret;
priority_queue<int, vector<int>, greater<int>> pq;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        pq.push(temp);
    }
}

void solve() {
    while (pq.size() != 1) {
        int fx = pq.top();
        pq.pop();
        int sx = pq.top();
        pq.pop();

        int sum = fx + sx;
        ret += sum;
        pq.push(sum);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}