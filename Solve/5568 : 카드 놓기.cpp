#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int N, K;
vector<int> v;
set<string> s;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
}

void solve() {
    do {
        string ret = "";
        for (int i = 0; i < K; i++) {
            ret += to_string(v[i]);
        }
        s.insert(ret);
    } while (next_permutation(v.begin(), v.end()));
    cout << s.size();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}