#include <iostream>
#include <set>

using namespace std;

int N;
int arr[4] = {1, 5, 10, 50};
set<int> str;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void go(int depth, int idx, int sum) {
    if (depth == N) {
        str.insert(sum);
        return;
    }

    for (int i = idx; i < 4; i++) {
        go(depth + 1, i, sum + arr[i]);
    }
}

void solve() {
    go(0, 0, 0);
    cout << str.size();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}