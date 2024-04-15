#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int visited[9];
vector<int> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
}

void go(int depth, vector<int> temp) {
    if (depth == M) {
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << ' ';
        }
        cout << '\n';
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            temp.push_back(arr[i]);
            go(depth + 1, temp);
            temp.pop_back();
            visited[i] = 0;
        }
    }
}

void solve() {
    vector<int> temp;
    go(0, temp);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}