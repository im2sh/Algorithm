#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<double> energy;
double ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        double temp;
        cin >> temp;
        energy.push_back(temp);
    }
    sort(energy.begin(), energy.end());
    ret = energy[N - 1];
}

void solve() {
    for (int i = 0; i < N - 1; i++) {
        ret += (energy[i] / 2);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}