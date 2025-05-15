#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct people {
    int team;
    int point;
} People;

int TC, N, num;
vector<People> teams;
vector<pair<People, int>> ret;
map<int, int> idx;
int visited[201];
pair<int, int> result[201];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    teams.clear();
    ret.clear();
    idx.clear();
    fill(&visited[0], &visited[0] + 201, 0);

    for (int i = 0; i < 201; i++) {
        result[i] = {0, 0};
    }

    vector<int> t;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        idx[temp]++;
        num = max(num, temp);
        t.push_back(temp);
    }

    int point = 1;
    for (int i = 0; i < N; i++) {
        if (idx[t[i]] >= 6) {
            teams.push_back({t[i], point++});
        }
    }
}

bool cmp(pair<People, int> A, pair<People, int> B) {
    if (A.first.point == B.first.point) {
        return A.second < B.second;
    }
    return A.first.point < B.first.point;
}

void solve() {
    while (TC--) {
        Input();
        for (int i = 0; i < teams.size(); i++) {
            if (visited[teams[i].team] > 3) {
                if (result[teams[i].team].second == 0)
                    result[teams[i].team].second = i;
                continue;
            }
            visited[teams[i].team]++;
            result[teams[i].team].first += teams[i].point;
        }

        for (int i = 1; i <= num; i++) {
            if (result[i].first == 0)
                continue;
            ret.push_back({{i, result[i].first}, result[i].second});
        }
        sort(ret.begin(), ret.end(), cmp);

        cout << ret[0].first.team << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}