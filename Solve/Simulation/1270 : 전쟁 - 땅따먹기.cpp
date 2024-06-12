#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

int N, M;
unordered_map<long long, int> war;
ll ret = -1;
ll maxNum = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    while (N--) {
        cin >> M;
        for (int i = 0; i < M; i++) {
            ll temp;
            cin >> temp;
            war[temp]++;
            if (war[temp] > maxNum) {
                maxNum = war[temp];
                ret = temp;
            }
        }

        int half = M / 2;
        if (maxNum > half) {
            cout << ret << '\n';
        } else {
            cout << "SYJKGW" << '\n';
        }
        war.clear();
        maxNum = 0;
        ret = -1;
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}