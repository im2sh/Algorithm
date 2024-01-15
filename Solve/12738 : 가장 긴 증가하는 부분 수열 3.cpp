#include <iostream>
#include <vector>

using namespace std;

int N, ret;
vector<int> arr;
vector<int> lis;

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
        arr.push_back(temp);
    }
}

int go(int target) {
    int low = 0;
    int high = lis.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (lis[mid] >= target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

void solve() {
    lis.push_back(arr[0]);
    for (int i = 1; i < N; i++) {
        if (arr[i] > lis[lis.size() - 1]) {
            lis.push_back(arr[i]);
        } else {
            int idx = go(arr[i]);
            lis[idx] = arr[i];
        }
    }
    cout << lis.size();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}