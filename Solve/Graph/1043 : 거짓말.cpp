#include <iostream>
#include <vector>

using namespace std;
int N, M, ret;
int cnt, num;
bool knowPeople[51];
int visited[51];
vector<vector<int>> party;
vector<int> graph[51];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    vector<int> temp;
    cin >> N >> M;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        cin >> num;
        knowPeople[num] = true;
    }
    int a, b;
    for (int i = 0; i < M; i++) {
        temp.clear();
        cin >> cnt;
        cin >> a;
        temp.push_back(a);
        for (int j = 1; j < cnt; j++) {
            cin >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            temp.push_back(b);
        }
        party.push_back(temp);
    }
}

void go(int here) {
    visited[here] = true;

    for (int i = 0; i < graph[here].size(); i++) {
        int next = graph[here][i];
        if (!visited[next]) {
            knowPeople[next] = true;
            go(next);
        }
    }

}

void solve() {
    for (int i = 1; i <= N; i++) {
        if (knowPeople[i])
            go(i);
    }
    for (auto &it: party) {
        bool flag = false;
        for (int i = 0; i < it.size(); i++) {
            if (knowPeople[it[i]])
                flag = true;
        }
        if (!flag) {
            ret++;
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}