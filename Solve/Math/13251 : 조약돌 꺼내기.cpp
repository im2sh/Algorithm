#include <iostream>

using namespace std;

int M, K, sum;
double ret;
int arr[51];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    cin >> K;
}

void solve() {
    for (int i = 0; i < M; i++) {
        double temp = 1.0;
        if (K > arr[i])
            continue;
        for (int j = 0; j < K; j++) {
            temp *= (double) (arr[i] - j) / (sum - j);
        }
        ret += temp;
    }
    cout << fixed;
    cout.precision(15);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}