#include <iostream>

using namespace std;

int N, K, cnt;
int prime[1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 2; i <= N; i++) {
        prime[i] = i;
    }
}

void solve() {
    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j = j + i) {
            if (prime[j] != 0) {
                prime[j] = 0;
                cnt++;
                if (cnt == K) {
                    cout << j;
                }
            }
        }
    }
}


int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}