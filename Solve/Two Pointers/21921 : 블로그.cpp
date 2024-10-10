#include <iostream>
#include <vector>

using namespace std;

int X, N, ret, maxDay = 1;
vector<int> days;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> X >> N;
    for (int i = 0; i < X; i++) {
        int temp;
        cin >> temp;
        days.push_back(temp);
    }
}

void solve() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += days[i];
    }
    ret = sum;
    for (int i = N; i < X; i++) {
        sum -= days[i - N];
        sum += days[i];
        if (ret < sum) {
            ret = sum;
            maxDay = 1;
        } else if (ret == sum) {
            maxDay++;
        }
    }
    if (ret == 0) {
        cout << "SAD";
    } else {
        cout << ret << '\n';
        cout << maxDay;
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}