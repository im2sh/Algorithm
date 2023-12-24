#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
string s;
string nums[11] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<pair<string, int>> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> M >> N;
}

void solve() {
    for (int i = M; i <= N; i++) {
        if (i >= 10) {
            s = nums[i / 10] + " " + nums[i % 10];
            ret.push_back({s, i});
        } else {
            s = nums[i % 10];
            ret.push_back({s, i});
        }
    }

    sort(ret.begin(), ret.end());

    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i].second << " ";
        if (i % 10 == 9)
            cout << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
