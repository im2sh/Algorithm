#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, ret;
vector<int> arr;
int visited[100001];

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
    int low = 0;
    int high = 0;
    visited[arr[low]]++;

    while (low <= high && high < N - 1) {
        high++;
        visited[arr[high]]++;
        if (visited[arr[high]] == K + 1) {
            while (true) {
                visited[arr[low]]--;
                low++;
                if (visited[arr[high]] == K) {
                    break;
                }
            }
        }
        ret = max(ret, high - low);
    }
    cout << ret + 1;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}