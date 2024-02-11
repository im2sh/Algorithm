#include <iostream>
#include <queue>

using namespace std;

int S, ret;
int visited[2001][2001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> S;
}

int BFS() {
    queue<pair<pair<int, int>, int>> q;
    q.push({{1, 0}, 0});
    visited[1][0] = 1;

    while (q.size()) {
        int paper = q.front().first.first;
        int clip = q.front().first.second;
        int time = q.front().second;
        q.pop();

        if (S == paper)
            return time;

        if (paper < 0 || paper > 1000 || clip < 0 || clip > 1000)
            continue;

        if (!visited[paper][paper]) {
            q.push({{paper, paper}, time + 1});
            visited[paper][paper] = 1;
        }
        if (!visited[paper + clip][clip]) {
            q.push({{paper + clip, clip}, time + 1});
            visited[paper + clip][clip] = 1;
        }
        if (!visited[paper - 1][clip] && paper != 0) {
            q.push({{paper - 1, clip}, time + 1});
            visited[paper - 1][clip] = 1;
        }
    }
}

void solve() {
    cout << BFS();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}