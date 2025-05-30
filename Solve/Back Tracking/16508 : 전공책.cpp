#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

string target;
int N, ret = INT_MAX;
vector<pair<int, string>> dict;
vector<string> choice;
int visited[26];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> target;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int t1;
        string t2;
        cin >> t1 >> t2;
        dict.push_back({t1, t2});
    }
}

void fillVisited() {
    fill(&visited[0], &visited[0] + 26, 0);
    for (int i = 0; i < target.size(); i++) {
        visited[target[i] - 'A']++;
    }
}

bool check() {
    fillVisited();
    for (int i = 0; i < choice.size(); i++) {
        for (int j = 0; j < choice[i].size(); j++) {
            if (visited[choice[i][j] - 'A'] > 0)
                visited[choice[i][j] - 'A']--;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (visited[i] > 0)
            return false;
    }
    return true;
}

void go(int idx, int sum) {
    if (check()) {
        ret = min(ret, sum);
        return;
    }

    for (int i = idx; i < N; i++) {
        choice.push_back(dict[i].second);
        go(i + 1, sum + dict[i].first);
        choice.pop_back();
    }
}

void solve() {
    go(0, 0);
    if (ret == INT_MAX)
        cout << -1;
    else
        cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}