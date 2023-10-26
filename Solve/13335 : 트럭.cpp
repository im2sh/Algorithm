#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int N, W, L;
queue<int> truck;
deque<pair<int, int>> bridge;
int ret;
int cnt;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> W >> L;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        truck.push(temp);
    }
}

void solve() {
    while (true) {
        if (truck.empty() && bridge.empty()) {
            cout << ret + 1;
            break;
        } else {
            ret++;
        }

        if (!truck.empty() && cnt + truck.front() <= L) {
            bridge.push_back({truck.front(), 0});
            cnt += truck.front();
            truck.pop();
        }

        for (int i = 0; i < bridge.size(); i++) {
            bridge[i].second++;
        }

        if (bridge.front().second == W) {
            cnt -= bridge.front().first;
            bridge.pop_front();
        }
    }
}


int main() {
    FastIO();
    Init();
    solve();
    return 0;
}