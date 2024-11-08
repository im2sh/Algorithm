#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int G;
vector<int> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> G;
}

void solve() {
    int low = 1;
    int high = 2;
    int weight = 0;

    while (low <= high && high <= G) {
        weight = pow(high, 2) - pow(low, 2);

        if (weight == G) {
            ret.push_back(high);
            high++;
        } else if (weight < G) {
            high++;
        } else {
            low++;
        }
    }
    if (!ret.size()) {
        cout << "-1";
        return;
    }

    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}