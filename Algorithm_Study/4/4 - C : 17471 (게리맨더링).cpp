#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int people[101];
int visited[11];
vector<int> town[11];
int group[11];
int ret = 987654321;
int cnt = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    int temp_n;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> people[i];

    for (int i = 1; i <= N; i++) {
        cin >> temp;
        for (int j = 0; j < temp; j++) {
            cin >> temp_n;
            town[i].push_back(temp_n);
        }
    }
}

void dfs(int here) {
    visited[here] = 1;
    cnt++;
    for (auto &it: town[here]) {
        if (group[here] != group[it])
            continue;
        if (visited[it])
            continue;
        dfs(it);
    }
}


int cal() {
    int diff1 = 0;
    int diff2 = 0;
    for (int i = 1; i <= N; i++) {
        if (group[i] == 1)
            diff1 += people[i];
        else
            diff2 += people[i];
    }

    return abs(diff1 - diff2);
}

void solve() {
    for (int i = 1; i <= (1 << N) - 1; i++) {
        int j1, j2;
        fill(&visited[0], &visited[0] + 11, 0);
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                group[j + 1] = 1;
                j1 = j + 1;
            } else {
                group[j + 1] = 0;
                j2 = j + 1;
            }
        }
        cnt = 0;

        dfs(j1);
        dfs(j2);

        if (cnt == N)
            ret = min(ret, cal());
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    if (ret == 987654321) {
        cout << "-1";
        return 0;
    }
    cout << ret << "\n";
    return 0;
}