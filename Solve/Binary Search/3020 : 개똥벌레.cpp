#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, H, ret, trickCnt = 987654321;
vector<int> jong, seok;
priority_queue<int, vector<int>, greater<int>> pq;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> H;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (i % 2 == 0)
            seok.push_back(temp);
        else
            jong.push_back(temp);
    }

    sort(jong.begin(), jong.end());
    sort(seok.begin(), seok.end());
}

void solve() {
    for (int i = 1; i <= H; i++) {
        int cnt = 0;
        int downIdx = lower_bound(seok.begin(), seok.end(), i) - seok.begin();
        cnt += seok.size() - downIdx;
        int upIdx = lower_bound(jong.begin(), jong.end(), H - i + 1) - jong.begin();
        cnt += jong.size() - upIdx;

        if (trickCnt > cnt)
            trickCnt = cnt;
        pq.push(cnt);
    }
    while (pq.size()) {
        if (pq.top() == trickCnt)
            ret++;
        pq.pop();
    }
    cout << trickCnt << " " << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
