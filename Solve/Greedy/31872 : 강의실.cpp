#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, ret;
vector<int> room;
vector<int> times;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        room.push_back(temp);
    }
    sort(room.begin(), room.end());
}

void solve() {
    int now = 0;
    for (int i = 0; i < N; i++) {
        times.push_back(room[i] - now);
        now = room[i];
    }

    sort(times.begin(), times.end());

    for (int i = 0; i < N - K; i++) {
        ret += times[i];
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}