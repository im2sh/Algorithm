#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ret;
vector<int> building;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        building.push_back(temp);
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        double maxH = -1e9;
        for (int j = i + 1; j < N; j++) {
            if (maxH < (double) (building[i] - building[j]) / (i - j)) {
                maxH = (double) (building[i] - building[j]) / (i - j);
                cnt++;
            }
        }
        maxH = 1e9;
        for (int j = i - 1; j >= 0; j--) {
            if (maxH > (double) (building[i] - building[j]) / (i - j)) {
                maxH = (double) (building[i] - building[j]) / (i - j);
                cnt++;
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}