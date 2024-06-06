#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int N, ret = 0;
int cnt[11];
int arr[1000001];
queue<int> q;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void go(int target) {
    int temp = arr[target];
    for (int i = 0; i < temp - 2; i++) {
        if (!cnt[i])
            continue;
        while (cnt[i] != 0) {
            cnt[q.front()]--;
            q.pop();
        }

    }
    for (int i = temp + 3; i <= 10; i++) {
        if (!cnt[i])
            continue;
        while (cnt[i] != 0) {
            cnt[q.front()]--;
            q.pop();
        }

    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        go(i);
        q.push(arr[i]);
        cnt[arr[i]]++;
        ret = max(ret, (int) q.size());
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}