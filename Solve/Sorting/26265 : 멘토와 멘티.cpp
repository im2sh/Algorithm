#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<string, string>> people;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string A, B;
        cin >> A >> B;
        people.push_back({A, B});
    }
}

bool cmp(pair<string, string> A, pair<string, string> B) {
    if (A.first == B.first) {
        return A.second > B.second;
    }
    return A.first < B.first;
}

void solve() {
    sort(people.begin(), people.end(), cmp);
    for (int i = 0; i < N; i++) {
        cout << people[i].first << ' ' << people[i].second << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}