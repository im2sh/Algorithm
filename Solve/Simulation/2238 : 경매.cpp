#include <iostream>
#include <vector>

using namespace std;

int U, N, ret;
string S;
int visited[10001];
vector<pair<string, int>> v;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> U >> N;
    visited[0] = 100000;

    for (int i = 0; i < N; i++) {
        string A;
        int B;
        cin >> A >> B;
        visited[B]++;
        v.push_back({A, B});
    }
}

void solve() {
    for (int i = 0; i < 10001; i++) {
        if (visited[i] > 0 && visited[i] < visited[ret]) {
            ret = i;
        }
    }

    for (int i = 0; i < N; i++) {
        if (v[i].second == ret) {
            cout << v[i].first << ' ' << ret;
            return;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}