#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
int visited[9];

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
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            visited[i]--;
            arr.push_back(i + 1);
            go(depth + 1);
            arr.pop_back();
            visited[i]++;
        }
    }

}

void solve() {
    fill(&visited[0], &visited[0] + 9, M);
    go(0);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
