#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> children;
priority_queue<int, vector<int>, less<>> pq;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        children.push_back(temp);
    }
}

void solve() {
    for (int i = 0; i < M; i++) {
        int present = pq.top();
        pq.pop();
        
        if (present < children[i]) {
            cout << "0";
            return;
        }
        pq.push(present - children[i]);
    }
    cout << "1";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}