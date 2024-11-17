#include <iostream>
#include <queue>

using namespace std;

int N, ret;
priority_queue<int, vector<int>> pq;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }
}

void solve() {
    while (pq.size()) {
        ret++;
        if (pq.size() > 1) {
            int one = pq.top();
            pq.pop();
            int two = pq.top();
            pq.pop();
            one--;
            two--;
            if (one != 0)
                pq.push(one);
            if (two != 0)
                pq.push(two);
        } else {
            int one = pq.top();
            pq.pop();
            one--;
            if (one != 0)
                pq.push(one);
        }
    }
    if (ret > 1440)
        ret = -1;
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}