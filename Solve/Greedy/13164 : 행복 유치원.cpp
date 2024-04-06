#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, K;
ll ret;
vector<int> people;
vector<int> diff;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        people.push_back(temp);
    }
    sort(people.begin(), people.end());
}

void solve() {
    for (int i = 1; i < N; i++) {
        diff.push_back(people[i] - people[i - 1]);
    }
    sort(diff.begin(), diff.end());

    for (int i = 0; i < N - K; i++) {
        ret += diff[i];
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}