#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> temp;
int arr[16];
bool visited[16];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        temp.push_back(t);
    }
    sort(temp.begin(), temp.end());
}

void go(int depth) {
    if (depth == (N * 2) - 1) {
        for (int i = 0; i < N * 2; i++) {
            cout << arr[i] << ' ';
        }
        exit(0);
    }

    if (arr[depth] != -1) {
        go(depth + 1);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i])
            continue;
        if (arr[depth] == -1 && arr[depth + temp[i] + 1] == -1 && (depth + temp[i] + 1) < N * 2) {
            visited[i] = true;
            arr[depth] = temp[i];
            arr[depth + temp[i] + 1] = temp[i];
            go(depth + 1);
            arr[depth] = -1;
            arr[depth + temp[i] + 1] = -1;
            visited[i] = false;
        }
    }
}

void solve() {
    fill(&arr[0], &arr[0] + 16, -1);
    go(0);
    cout << -1;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}