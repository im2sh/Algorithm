#include <iostream>
#include <queue>
#include <vector>

#define MAXMOVE 100004

using namespace std;

int N, K;
int visited[MAXMOVE];
int path[MAXMOVE];
vector<int> result;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
}

void solve() {
    queue<int> q;
    q.push(N);
    visited[N] = 1;
    if (N == K) {
        cout << "0" << "\n" << K;
        return;
    }
    while (q.size()) {
        int x = q.front();
        q.pop();

        for (int next: {x + 1, x - 1, x * 2}) {
            if (next < 0 || next >= MAXMOVE)
                continue;
            if (!visited[next]) {
                visited[next] = visited[x] + 1;
                q.push(next);
                path[next] = x;
            }
        }
    }
    result.push_back(K);
    for (int i = K; path[i] != N;) {
        int temp = path[i];
        result.push_back(temp);
        i = temp;
    }
    result.push_back(N);
    cout << visited[K] - 1 << "\n";
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }
}


int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}