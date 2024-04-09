#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, ret;
vector<int> arr;
int target;

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

    sort(arr.begin(), arr.end());
}

void solve() {
    for (int i = 0; i < N; i++) {
        target = arr[i];
        bool canMake = false;
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;
            int low = 0;
            int high = N - 1;

            while (low <= high) {
                int mid = (low + high) / 2;
                if (mid == j || mid == i) {
                    high = mid - 1;
                    continue;
                }
                if (arr[j] + arr[mid] == target) {
                    canMake = true;
                    break;
                } else if (arr[j] + arr[mid] > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (canMake) {
                ret++;
                break;
            }
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}