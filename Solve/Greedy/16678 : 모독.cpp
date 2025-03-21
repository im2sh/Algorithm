#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll N, ret;
vector<ll> people;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll temp;
        cin >> temp;
        people.push_back(temp);
    }
    sort(people.begin(), people.end());
}

void solve() {
    if (people[0] != 0) {
        ret += people[0] - 1;
        people[0] = 1;
    }

    for (int i = 1; i < N; i++) {
        if (people[i] - people[i - 1] > 1) {
            ret += people[i] - people[i - 1] - 1;
            people[i] = people[i - 1] + 1;
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