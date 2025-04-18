#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<string, float>> people;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {

}

bool cmp(pair<string, float> a, pair<string, float> b) {
    return a.second > b.second;
}

void Input() {
    people.clear();
    cin >> N;
    for (int i = 0; i < N; i++) {
        string name;
        float h;

        cin >> name >> h;
        people.push_back({name, h});
    }
    sort(people.begin(), people.end(), cmp);
}

void solve() {
    while (true) {
        Input();
        if (N == 0)
            break;
        for (int i = 0; i < N; i++) {
            if (people[i].second == people[0].second) {
                cout << people[i].first << ' ';
            }
        }
        cout << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}