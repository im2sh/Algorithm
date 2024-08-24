#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ret, cnt;
int p[6];
vector<int> problem[6];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < 5; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < N; i++) {
        int k, t;
        cin >> k >> t;
        problem[k - 1].push_back(t);
    }
    for (int i = 0; i < 5; i++) {
        sort(problem[i].begin(), problem[i].end());
    }
}

void solve() {
    for (int i = 0; i < 5; i++) {
        cnt++;
        for (int j = 0; j < p[i]; j++) {
            if (j == 0) {
                ret += problem[i][j];
                if (cnt != 1) {
                    ret += 60;
                }
            } else {
                ret += 2 * problem[i][j] - problem[i][j - 1];
            }
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