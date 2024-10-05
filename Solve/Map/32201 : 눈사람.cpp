#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, maxDiff;
vector<int> B, ret;
map<int, int> dict;

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
        dict[temp] = i + 1;
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        int num = dict[temp];
        B.push_back(temp);
        dict[temp] = num - (i + 1);
        maxDiff = max(maxDiff, num - (i + 1));
    }

    for (int i = 0; i < N; i++) {
        if (dict[B[i]] == maxDiff) {
            ret.push_back(B[i]);
        }
    }

    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << ' ';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}