#include <iostream>

using namespace std;

int N;
int seq[11];
int result[11];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> seq[i];
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (!result[j] && cnt == seq[i]) {
                result[j] = i;
                break;
            } else if (!result[j]) {
                cnt++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << ' ';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}