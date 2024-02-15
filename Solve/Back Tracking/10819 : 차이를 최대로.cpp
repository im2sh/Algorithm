#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ret = -1;
vector<int> arr;
vector<int> temp;
int visited[8];


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int tem;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tem;
        arr.push_back(tem);
    }
}

void cal() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (i == N - 1)
            break;
        sum += abs(temp[i] - temp[i + 1]);
    }

    ret = max(ret, sum);
}

void dfs(int depth) {
    if (depth == N) {
        cal();
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            temp.push_back(arr[i]);
            dfs(depth + 1);
            temp.pop_back();
            visited[i] = 0;
        }
    }
}

void solve() {
    dfs(0);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}