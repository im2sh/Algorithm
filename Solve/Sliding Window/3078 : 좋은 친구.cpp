#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K, low, high;
long long ret;
vector<int> friends;
int visited[21];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        friends.push_back(S.length());
    }

    for (int i = 0; i <= K; i++) {
        if (visited[friends[i]] != 0)
            ret += visited[friends[i]];
        visited[friends[i]]++;
    }
    high = K;
}

void solve() {
    while (high < N - 1) {
        visited[friends[low]]--;
        low++;

        high++;
        if (visited[friends[high]])
            ret += visited[friends[high]];
        visited[friends[high]]++;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}