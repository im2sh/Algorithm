#include <iostream>

using namespace std;
int N, ret;
int arr[101][101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        for (int y = a; y < a + 10; y++) {
            for (int x = b; x < b + 10; x++) {
                if (!arr[y][x]) {
                    arr[y][x] = 1;
                    ret++;
                }
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