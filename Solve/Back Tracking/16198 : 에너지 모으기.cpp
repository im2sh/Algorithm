#include <iostream>
#include <algorithm>

using namespace std;
int N, ret = -1;
int ball[10];
int visited[10];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> ball[i];
    }
}

void go(int depth, int sum) {
    if (depth == N - 2) {
        ret = max(ret, sum);
        return;
    }
    for (int i = 1; i < N - 1; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            int a = 0;
            int b = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (!visited[j]) {
                    a = ball[j];
                    break;
                }
            }

            for (int j = i + 1; j < N; j++) {
                if (!visited[j]) {
                    b = ball[j];
                    break;
                }
            }

            sum += a * b;
            go(depth + 1, sum);
            sum -= a * b;
            visited[i] = 0;
        }
    }
}

void solve() {
    go(0, 0);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}