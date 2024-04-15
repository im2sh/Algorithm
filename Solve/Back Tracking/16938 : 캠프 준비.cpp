#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, L, R, X, ret;
vector<int> arr;
bool visited[16];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> L >> R >> X;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
}

bool check(vector<int> temp) {
    if (temp.size() <= 1)
        return false;
    int diff = abs(temp[0] - temp[temp.size() - 1]);
    if (diff < X)
        return false;

    int sum = 0;
    for (int i = 0; i < temp.size(); i++) {
        sum += temp[i];
    }
    if (L <= sum && sum <= R) {
        return true;
    }
    return false;
}

void go(int idx, vector<int> temp) {
    if (temp.size() > N)
        return;
    if (check(temp))
        ret++;

    for (int i = idx; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            temp.push_back(arr[i]);
            go(i + 1, temp);
            temp.pop_back();
            visited[i] = false;
        }
    }
}

void solve() {
    vector<int> temp;
    go(0, temp);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
