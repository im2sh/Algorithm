#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, Q;
vector<int> car;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        car.push_back(temp);
    }
    sort(car.begin(), car.end());
}

int binary_search(int target) {
    int low = 0;
    int high = N - 1;
    int mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (target == car[mid]) {
            return mid;
        } else if (target < car[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

void solve() {
    int target = 0;
    while (Q--) {
        cin >> target;
        int m = binary_search(target);
        if (m == -1) {
            cout << "0\n";
        } else {
            cout << m * (N - m - 1) << '\n';
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}