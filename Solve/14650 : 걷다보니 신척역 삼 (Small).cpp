#include <iostream>

using namespace std;

int N;
int arr[10][3];
int ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

int go(int depth, int number, int sum) {
    if (depth == N) {
        if (sum % 3 == 0)
            return 1;
        return 0;
    }
    int ret = arr[depth][number];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 0; i < 3; i++) {
        ret += go(depth + 1, i, sum + i);
    }
    return ret;
}

void solve() {
    memset(arr, -1, sizeof(arr));
    cout << go(1, 1, 1) + go(1, 2, 2);

}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}