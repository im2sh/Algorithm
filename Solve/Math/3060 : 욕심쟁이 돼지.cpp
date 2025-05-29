#include <iostream>

using namespace std;

int TC, N, sum, day, times;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    cin >> N;
    sum = 0;
    day = 0;
    times = 1;
    for (int i = 0; i < 6; i++) {
        int temp;
        cin >> temp;
        sum += temp;
    }
}

void solve() {
    while (TC--) {
        Input();

        while (true) {
            ++day;
            if (N - (sum * times) < 0)
                break;
            times *= 4;
        }
        cout << day << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}