#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N;
map<string, int> dict;
pair<int, string> people[101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        dict.insert(make_pair(temp, i));
        people[i].second = temp;
    }
}

void solve() {
    string temp;
    while (cin >> temp)
        people[dict[temp]].first--;

    sort(people, people + N);

    for (int i = 0; i < N; i++)
        cout << people[i].second << ' ' << -people[i].first << '\n';
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}