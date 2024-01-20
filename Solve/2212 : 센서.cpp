#include <iostream>
#include <vector>

using namespace std;

int N, K, ret;
vector<int> sensor;
vector<int> dist;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N;
    cin >> K;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        sensor.push_back(temp);
    }
    sort(sensor.begin(), sensor.end());
}

void solve() {
    for (int i = 0; i < N - 1; i++) {
        int temp = sensor[i + 1] - sensor[i];
        dist.push_back(temp);
    }
    sort(dist.begin(), dist.end());
    for (int i = 0; i < (N - K); i++) {
        ret += dist[i];
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}