#include <iostream>
#include <cmath>

using namespace std;
int N, temp, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {

}

void solve() {
    while (1) {
        cin >> N;
        if (!N)
            break;

        for (int i = N + 1; i <= 2 * N; i++) {
            temp = sqrt(i);
            if (temp == 1 && i != 1) {
                ret++;
                continue;
            }
            if (i % 2) {
                for (int j = 2; j <= temp; j++) {
                    if (!(i % j))
                        break;
                    if (j == temp) {
                        ret++;
                    }
                }
            }
        }
        cout << ret << '\n';
        ret = 0;
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}