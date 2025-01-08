#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
ll M, ret;
vector<ll> hole;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        ll temp;
        cin >> temp;
        hole.push_back(temp);
    }
}

void solve() {
    int low = 0;
    int high = 1;
    ll sum = hole[low] + hole[high];

    while (low <= high && high < N) {
        if (sum <= M) {
            ret = max(ret, sum);
            high++;
            sum += hole[high];
        } else {
            if (low == high && high < N) {
                high++;
                sum += hole[high];
            }
            sum -= hole[low++];
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}