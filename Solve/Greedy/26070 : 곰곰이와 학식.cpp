#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll ret;
int people[3];
int coupon[3];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> people[0] >> people[1] >> people[2];
    cin >> coupon[0] >> coupon[1] >> coupon[2];
}

void solve() {
    for (int ratio: {1, 3, 9}) {
        for (int i = 0; i < 3; i++) {
            int idx = i;
            if (ratio == 3)
                idx = (i + 2) % 3;
            else if (ratio == 9)
                idx = (i + 1) % 3;
            int temp = min(people[i], coupon[idx] / ratio);
            people[i] -= temp;
            coupon[idx] -= temp * ratio;
            ret += temp;
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
