#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
vector<pair<int, int>> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
}

bool cmp(pair<int, int> A, pair<int, int> B) {
    if (A.second < B.second)
        return A.second > B.second;
    else if (A.second == B.second)
        return A.first < B.first;
    return A.second > B.second;
}

void solve() {
    for (int i = 0; i < M; i++) {
        int temp;
        int score = 0;
        cin >> temp;
        for (int j = 0; j < N; j++) {
            char OX;
            cin >> OX;
            if (OX == 'O')
                score += arr[j];
        }
        ret.push_back({temp, score});
    }
    sort(ret.begin(), ret.end(), cmp);
    cout << ret[0].first << ' ' << ret[0].second;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}