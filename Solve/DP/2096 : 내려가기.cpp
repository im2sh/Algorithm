#include <iostream>
#include <algorithm>

using namespace std;

int N, maxRet, minRet = 987654321;
int MAX_DP[3];
int MIN_DP[3];
int max_arr[3];
int min_arr[3];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N;
    for (int i = 0; i < 3; i++) {
        cin >> temp;
        max_arr[i] = temp;
        min_arr[i] = temp;
        MAX_DP[i] = temp;
        MIN_DP[i] = temp;
    }
}

void solve() {
    int a, b, c;
    for (int i = 1; i < N; i++) {
        cin >> a >> b >> c;
        MAX_DP[0] = max(max_arr[0], max_arr[1]) + a;
        MIN_DP[0] = min(min_arr[0], min_arr[1]) + a;

        int center = max(max_arr[0], max_arr[1]);
        MAX_DP[1] = max(center, max_arr[2]) + b;

        center = min(min_arr[0], min_arr[1]);
        MIN_DP[1] = min(center, min_arr[2]) + b;

        MAX_DP[2] = max(max_arr[1], max_arr[2]) + c;
        MIN_DP[2] = min(min_arr[1], min_arr[2]) + c;

        for (int j = 0; j < 3; j++) {
            max_arr[j] = MAX_DP[j];
            min_arr[j] = MIN_DP[j];
        }
    }


    for (int i = 0; i < 3; i++) {
        maxRet = max(maxRet, MAX_DP[i]);
    }

    for (int i = 0; i < 3; i++) {
        minRet = min(minRet, MIN_DP[i]);
    }

    cout << maxRet << " " << minRet;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}