#include <iostream>

using namespace std;

int N, M;
bool visited[9];
vector<int> temp;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
}

void go(int depth) {
    if (depth == M) {
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            temp.push_back(i + 1);
            go(depth + 1);
            temp.pop_back();
            visited[i] = false;
        }
    }
}

void solve() {
    go(0);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}