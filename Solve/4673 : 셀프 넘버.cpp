#include <iostream>

using namespace std;
int n, sum;
bool check[10001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {

}

void solve() {
    for (int i = 1; i < 10001; i++) {
        sum = 0;
        n = i;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        if (i + sum < 10001) {
            check[i + sum] = true;
        }
    }
    for (int i = 1; i < 10001; i++) {
        if (!check[i]) {
            cout << i << '\n';
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
