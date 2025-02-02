#include <iostream>
#include <vector>

using namespace std;

int N, K, ret;
vector<int> arr;
int visited[151];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
}

void solve() {
    int target = arr[0];
    while (!visited[target]) {
        ret++;
        visited[target] = true;
        if (target == K) {
            cout << ret;
            return;
        }
        target = arr[target];
    }
    cout << "-1";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

