#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, T, G;
int visited[100001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> T >> G;
    fill(&visited[0], &visited[0] + 100001, 987654321);
}

void go() {
    queue<pair<int, int>> q;
    visited[0] = 1;
    q.push({N, 0});

    while (q.size()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == G && cnt <= T) {
            cout << cnt;
            return;
        }
        if (cnt > T || cur > 99999) {
            break;
        }

        for (auto &it: {cur + 1, cur * 2}) {
            if (it > 99999)
                continue;
            if (it == cur + 1) {
                if (visited[it] > cnt + 1) {
                    visited[it] = cnt + 1;
                    q.push({it, cnt + 1});
                }
            } else {
                string temp = to_string(it);
                if (it == 0)
                    continue;
                int ti = temp[0] - '0';
                ti--;
                int tc = ti + '0';
                temp[0] = tc;
                int next = stoi(temp);

                if (visited[next] > cnt + 1) {
                    visited[next] = cnt + 1;
                    q.push({next, cnt + 1});
                }
            }
        }
    }
    cout << "ANG";
}

void solve() {
    go();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}