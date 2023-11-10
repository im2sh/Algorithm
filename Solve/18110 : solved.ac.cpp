#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> n;
}

void solve() {
    if (n == 0) {
        cout << ret;
        return;
    }
    vector<int> numbers(n);

    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    sort(numbers.begin(), numbers.end());

    int idx = round(n * 0.15);
    double sum = 0;

    for (int i = idx; i < n - idx; i++)
        sum += numbers[i];

    ret = round(sum / (n - idx * 2));

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}