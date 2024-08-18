#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N;
vector<int> arr;
vector<int> ret;
bool visited[21];
map<int, bool> M;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    M[0] = true;
}

void go(int idx, int temp) {
    if (temp != 0)
        M[temp] = true;
    for (int i = idx; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            go(i + 1, temp + arr[i]);
            visited[i] = false;
        }
    }
}

void solve() {
    go(0, 0);
    if (!M[1]) {
        cout << "1";
        return;
    }
    for (auto it: M) {
        if (it.first == 0)
            continue;
        int cur = it.first;
        if (!M[cur - 1]) {
            cout << it.first - 1;
            return;
        } else if (!M[cur + 1]) {
            cout << it.first + 1;
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
