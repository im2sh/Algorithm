#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int N;
vector<pair<int, int>> arr;
vector<int> lis;
stack<int> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arr.push_back({0, temp});
    }
}

int go(int target) {
    int low = 0;
    int high = lis.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (target <= lis[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

void solve() {
    int len = 1;
    lis.push_back(arr[0].second);
    for (int i = 1; i < N; i++) {
        if (arr[i].second > lis[lis.size() - 1]) {
            lis.push_back(arr[i].second);
            arr[i].first = len++;
        } else {
            int idx = go(arr[i].second);
            lis[idx] = arr[i].second;
            arr[i].first = idx;
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        if (arr[i].first == len - 1) {
            ret.push(arr[i].second);
            len--;
        }
    }
    cout << ret.size() << '\n';
    while (ret.size()) {
        cout << ret.top() << ' ';
        ret.pop();
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}