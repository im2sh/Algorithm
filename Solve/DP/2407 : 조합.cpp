#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
string DP[104][104];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
}

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                DP[i][j] = "1";
            else {
                int sum = 0;
                string n1 = DP[i - 1][j];
                string n2 = DP[i - 1][j - 1];

                while (!n1.empty() || !n2.empty() || sum) {
                    if (!n1.empty()) {
                        sum += n1.back() - '0';
                        n1.pop_back();
                    }
                    if (!n2.empty()) {
                        sum += n2.back() - '0';
                        n2.pop_back();
                    }
                    DP[i][j].push_back((sum % 10) + '0');
                    sum /= 10;
                }
                reverse(DP[i][j].begin(), DP[i][j].end());
            }
        }
    }
    cout << DP[N][M];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
