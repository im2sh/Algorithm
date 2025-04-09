#include <iostream>
#include <vector>

using namespace std;

int N, maxNum;
int arr[1001];
int lis[1001];
int result[1001];
vector<int> ret;

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

int go(int low, int high, int target) {
    while (low < high) {
        int mid = (low + high) / 2;

        if (lis[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return high;
}

void solve() {
    int i = 1;
    int j = 0;
    lis[0] = arr[0];
    result[0] = 0;
    while (i < N) {
        if (arr[i] > lis[j]) {
            lis[j + 1] = arr[i];
            result[i] = j + 1;
            j++;
        } else {
            int idx = go(0, j, arr[i]);
            lis[idx] = arr[i];
            result[i] = idx;
        }
        maxNum = max(maxNum, result[i]);
        i++;
    }
    cout << j + 1 << '\n';

    for (i = N - 1; i >= 0; i--) {
        if (maxNum == result[i]) {
            maxNum--;
            ret.push_back(arr[i]);
        }
    }

    for (i = ret.size() - 1; i >= 0; i--) {
        cout << ret[i] << ' ';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}