#include <iostream>

using namespace std;

int N, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 0; i < N; i++) {
        int interval, time, sum;

        cin >> interval >> time;
        sum = time + interval;

        int temp = ret % sum;
        ret++;

        if (temp < time)
            ret += (time - temp);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}