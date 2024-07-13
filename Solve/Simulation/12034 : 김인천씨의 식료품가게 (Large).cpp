#include <iostream>
#include <vector>

using namespace std;

int TC, N;
vector<int> cost;
vector<int> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void solve() {
    for (int t = 1; t <= TC; t++) {
        cost.clear();
        ret.clear();
        cin >> N;

        for (int i = 0; i < 2 * N; i++) {
            int temp;
            cin >> temp;
            cost.push_back(temp);
        }

        for (int i = 0; i < cost.size(); i++) {
            int now = cost[i];
            if (now == 0)
                continue;
            int origin = now / 3;
            origin *= 4;
            for (int j = i + 1; j < cost.size(); j++) {
                if (cost[j] == origin) {
                    ret.push_back(now);
                    cost[j] = 0;
                    break;
                }
            }
        }
        cout << "Case #" << t << ": ";
        for (auto i: ret) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}