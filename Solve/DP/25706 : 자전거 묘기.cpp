#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;
int DP[200001];

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
        arr.push_back(temp);
    }
}

void solve() {
    for (int i = N - 1; i >= 0; i--) {
        if (i == N - 1) {
            DP[i] = 1;
        } else {
            if (arr[i] == 0) {
                DP[i] = DP[i + 1] + 1;
            } else {
                if (i + arr[i] + 1 >= N) {
                    DP[i] = 1;
                } else {
                    DP[i] = DP[i + arr[i] + 1] + 1;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << DP[i] << " ";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
