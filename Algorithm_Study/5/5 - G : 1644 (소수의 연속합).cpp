#include <iostream>

using namespace std;

int N;
int k;
int temp[4000001];
int prime[4000001];
int ret;
int l, r;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 2; i <= N; i++) {
        if (temp[i])
            continue;
        for (int j = i * 2; j <= N; j += i) {
            temp[j] = 1;
        }
    }

    for (int i = 2; i <= N; i++) {
        if (!temp[i])
            prime[k++] = i;
    }
}

void solve() {
    int sum = 0;
    while (1) {
        if (sum > N)
            sum -= prime[l++];
        else if (r == k)
            break;
        else if (r <= k)
            sum += prime[r++];
        if (sum == N)
            ret++;
    }
    cout << ret << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}