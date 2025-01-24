#include <iostream>
#include <cmath>

using namespace std;

double N, ret;
pair<double, double> arr[3];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < 3; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
}

double cal(double mid, double target) {
    return mid + fabs(mid - target);
}

void go(int idx, double &left, double &right) {
    if (arr[idx].first == arr[idx].second)
        return;

    double mid = (arr[idx].first + arr[idx].second) / 2;

    for (int i = idx + 1; i < 3; i++) {
        arr[i].first = cal(mid, arr[i].first);
        arr[i].second = cal(mid, arr[i].second);
    }
    left = cal(mid, left);
    if (left > right)
        right = left;
    left = mid;
}

void solve() {
    double left = 0;
    double right = N;
    for (int i = 0; i < 3; i++)
        go(i, left, right);
    ret = right - left;
    ret *= 10;
    ret = floor(ret);
    ret /= 10;
    cout << fixed;
    cout.precision(1);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}