#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct team {
    string name;
    int score;
    int penalty;
};

int N, K;

unordered_map<string, team> teams;
vector<pair<string, team>> result;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    cin.ignore();
}

bool cmp(pair<string, team> a, pair<string, team> b) {
    if (a.second.score == b.second.score)
        return a.second.penalty < b.second.penalty;
    return a.second.score > b.second.score;
}

void solve() {
    for (int i = 0; i < N; i++) {
        string S;
        getline(cin, S);
        string temp = "";
        string university = "";
        string teamName = "";
        string penalty = "";
        string score = "";
        for (int j = 0; j < S.length(); j++) {
            if (S[j] == ' ') {
                if (university.size() == 0)
                    university = temp;
                else if (teamName.size() == 0)
                    teamName = temp;
                else if (penalty.size() == 0)
                    score = temp;
                temp = "";
            } else {
                temp += S[j];
            }
            if (j == S.length() - 1)
                penalty = temp;
        }

        int intScore = stoi(score);
        int intPenalty = stoi(penalty);

        if (teams.find(university) == teams.end()) {
            teams.insert({university, {teamName, intScore, intPenalty}});
        } else {
            if (intScore > teams[university].score) {
                teams[university] = {teamName, intScore, intPenalty};
            } else if (intScore == teams[university].score) {
                if (teams[university].penalty > intPenalty) {
                    teams[university] = {teamName, intScore, intPenalty};
                }
            }
        }
    }
    for (auto &it: teams) {
        result.push_back({it.first, it.second});
    }

    sort(result.begin(), result.end(), cmp);

    for (int i = 0; i < K; i++) {
        cout << result[i].second.name << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}