#include <iostream>

using namespace std;
int N, K, ret;
string line;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    cin >> line;
}

void solve() {
    for (int i = 0; i < N; i++) {
        if (line[i] != 'P')
            continue;
        for (int j = i - K; j <= i + K; j++) {
            if (0 <= j && j < N && line[j] == 'H') {
                line[j] = '-';
                ret++;
                break;
            }
        }
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

