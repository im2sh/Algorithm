#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<double, vector<double>, greater<double>> pq;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        double temp;
        cin >> temp;
        pq.push(temp);
    }
}

void solve() {
    cout.precision(3);
    cout << fixed;
    for (int i = 0; i < 7; i++) {
        cout << pq.top() << '\n';
        pq.pop();
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}