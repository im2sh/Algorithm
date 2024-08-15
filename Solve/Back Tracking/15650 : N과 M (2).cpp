#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[9];
vector<int> temp;
bool visited[9];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < 9; i++) {
        arr[i] = i + 1;
    }
}

void go(int depth, int idx) {
    if (depth == M) {
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            temp.push_back(arr[i]);
            go(depth + 1, i + 1);
            temp.pop_back();
            visited[i] = false;
        }
    }
}

void solve() {
    go(0, 0);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}