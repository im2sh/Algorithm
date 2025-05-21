#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int TC;
vector<pair<int, int>> pos;
vector<int> result;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    pos.clear();
    result.clear();
    for (int i = 0; i < 4; i++) {
        int x, y;
        cin >> x >> y;
        pos.push_back({x, y});
    }
}

void solve() {
    while (TC--) {
        Input();

        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                result.push_back(pow(pos[i].second - pos[j].second, 2) + pow(pos[i].first - pos[j].first, 2));
            }
        }

        sort(result.begin(), result.end());
        if (result[0] == result[1] && result[1] == result[2] && result[2] == result[3] && result[4] == result[5])
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}