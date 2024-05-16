#include <iostream>

using namespace std;
int N, ret = 987654321;
int house[1000][3];
int DP[3];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> house[i][0] >> house[i][1] >> house[i][2];
    }
}

void solve() {
    DP[0] = house[0][0];
    DP[1] = house[0][1];
    DP[2] = house[0][2];

    for (int i = 1; i < N; i++) {
        int temp[3];
        temp[0] = DP[0];
        temp[1] = DP[1];
        temp[2] = DP[2];
        DP[0] = min((house[i][0] + temp[1]), (house[i][0] + temp[2]));
        DP[1] = min((house[i][1] + temp[0]), (house[i][1] + temp[2]));
        DP[2] = min((house[i][2] + temp[0]), (house[i][2] + temp[1]));
    }

    for (int i = 0; i < 3; i++) {
        ret = min(ret, DP[i]);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}