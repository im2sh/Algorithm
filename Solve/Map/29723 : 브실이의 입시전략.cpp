#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
unordered_map<string, int> dict;
vector<string> releasedSubjects;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; ++i) {
        string subject;
        int score;
        cin >> subject >> score;
        dict[subject] = score;
    }

    for (int i = 0; i < K; ++i) {
        string temp;
        cin >> temp;
        releasedSubjects.push_back(temp);
    }
}

void solve() {
    int releasedSum = 0;

    for (auto it: releasedSubjects) {
        releasedSum += dict[it];
        dict.erase(it);
    }

    vector<int> remainingScores;
    for (auto it: dict) {
        remainingScores.push_back(it.second);
    }
    sort(remainingScores.begin(), remainingScores.end());

    int minSum = 0, maxSum = 0;
    int needToPick = M - K;

    for (int i = 0; i < needToPick; ++i) {
        minSum += remainingScores[i];
        maxSum += remainingScores[remainingScores.size() - 1 - i];
    }

    cout << releasedSum + minSum << " " << releasedSum + maxSum << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}